//we already have a method to valicate additional funds validaateAdditionalFunds

function handleAdditionalFunds(index, type) {
    var tempObj = [];
    if (type === "additionalFunds") {
        if (vmSettlementDetail.view.settlementPlanner.additionalCharge && vmSettlementDetail.view.settlementPlanner.additionalCharge.length > 0) {
            vmSettlementDetail.view.settlementPlanner.additionalCharge.map(function (item, addFundsIndex) {
                item["isChanged"] = !!!item["isChanged"] ? addFundsIndex == index ? true : false : true;
                var obj = angular.copy(item);
                obj["isAdditionalFunds"] = true;
                obj["isPayment"] = false;
                obj["isAdjust"] = true;
                obj["isChanged"] = true;
                tempObj.push(obj);
            });
        }
    }

    let currentCreditor = $filter('filter')(tempLoanListDetail.view.loanDetail.lenders, function (lender) {
                                return lender.is_active;
                            })[0];
    let lastFourAccountNumber = currentCreditor.account_number && currentCreditor.account_number.length > 4 ? currentCreditor.account_number.substr(currentCreditor.account_number.length - 4, 4) : currentCreditor.account_number;
    let offerId = vmSettlementDetail.view.editOffer.active ? vmSettlementDetail.view.editOffer.offer.id : null;
    let indexList = extractOfferAdditionalFundsFromRunningBalance(offerId, type);
    let keys = Object.keys(indexList);

    let removedForecastItems = 0;
    for (let indexCount = 0; indexCount < keys.length; indexCount++) {
        let forecastIndex = keys[indexCount] - removedForecastItems;
        var isPaymentExists = false;
        var isFeeExists = false;
        if (!!!offerId) {
            isPaymentExists = vmSettlementDetail.view.settlementPlanner.lenderPaymentSchedules.some(function (item) {
                return new Date(item.date).getTime() ===
                    new Date(vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].date).getTime()
                    && !!(parseFloat(item.amount) && notImpactingPaymentModeType.indexOf(item.Code) === -1);
            });
            isFeeExists = vmSettlementDetail.view.settlementPlanner.serviceFeePaymentSchedules.some(function (item) {
                return new Date(item.date).getTime() ===
                    new Date(vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].date).getTime()
                    && !!(parseFloat(item.amount));
            });
            if (!isPaymentExists && !isFeeExists) {
                vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].is_changed = false;
            }
        }
        let oldAmount = 0.0;
        for (let count = 0; count < indexList[keys[indexCount]].length; count++) {
            indexList[keys[indexCount]][count] -= count;
            oldAmount += parseFloat(vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].details[indexList[keys[indexCount]][count]].amount);
            vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].details.splice(indexList[keys[indexCount]][count], 1);
        }
        addBalanceInForecast(forecastIndex, oldAmount);

        //manage background color on edit offer area
        if (!!offerId) {
            isPaymentExists = vmSettlementDetail.view.settlementPlanner.lenderPaymentSchedules.some(function (item) {
                return new Date(item.date).getTime() ===
                    new Date(vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].date).getTime()
                    && !!(parseFloat(item.amount)) && !!item["isChanged"];
            });
            isFeeExists = vmSettlementDetail.view.settlementPlanner.serviceFeePaymentSchedules.some(function (item) {
                return new Date(item.date).getTime() ===
                    new Date(vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].date).getTime()
                    && !!(parseFloat(item.amount)) && !!item["isChanged"];
            });
            if (!isPaymentExists && !isFeeExists) {
                vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].is_changed = false;
            }
        }

        // Remove balance forecast's record if no detail exists on it
        if (!isPaymentExists && !isFeeExists
            && forecastIndex != 0
            && vmSettlementDetail.view.settlementMetaData.balanceForecast[forecastIndex].details.length == 0) {
            vmSettlementDetail.view.settlementMetaData.balanceForecast.splice(forecastIndex, 1);
            removedForecastItems += 1;
        }
    }

    //adding new details
    for (let count = 0; count < tempObj.length; count++) {
        let amount = !!tempObj[count].amount ? parseFloat(tempObj[count].amount) : 0.0;
        if (amount) {
            let newAmount = (!!tempObj[count].amount ? parseFloat(tempObj[count].amount) : 0) + (!!tempObj[count].fee ? parseFloat(tempObj[count].fee) : 0);
            let newIndex = findIndexByDateInBalanceForecast(tempObj[count].date);
            //manage running balance background color of impact date
            if (!!!offerId) {
                // in case of generate/regenerate plan
                vmSettlementDetail.view.settlementMetaData.balanceForecast[newIndex].is_changed = true;
                vmSettlementDetail.view.settlementMetaData.balanceForecast[newIndex].is_adjust = true;
            } else {
                // in case of edit offer
                if (!!tempObj[count]["isChanged"]) {
                    vmSettlementDetail.view.settlementMetaData.balanceForecast[newIndex].is_changed = true;
                    vmSettlementDetail.view.settlementMetaData.balanceForecast[newIndex].is_adjust = true;
                }
            }
            let description = null;
            let type = null;
            if ((tempObj[count].isAdditionalFunds)) {
                description = `Additional Funds ${currentCreditor.lender_name}, ${lastFourAccountNumber}`;
                type = 0;
            }
            vmSettlementDetail.view.settlementMetaData.balanceForecast[newIndex].details.push(
                createRunningBalanceDetailItem(tempObj[count].amount, tempObj[count].date, null, true, description, tempObj[count].id, null, offerId, type));

            addBalanceInForecast(newIndex, newAmount);
        }
    }
    
}