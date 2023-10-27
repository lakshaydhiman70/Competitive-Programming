/* =============================================        
   Created By: UNKNOWN        
   Created On: UNKNOWN        
   Description:         
        
   Updated By: David Waters        
   Updated On: 01/03/2022        
   Trello Card: https://trello.com/c/KIZIw9n7/665-negotiator-dashboards        
   Description: Added CODE TO UPDATE [task].[Ticket] SET ResolvedDate         
      
   Updated By: Arpit        
   Updated On: 30/03/2022        
   Trello Card: AC-646      
   Description: Added CODE TO UPDATE LoanSettlementOffer.OfferStatusId SET 6         
   ============================================= */
CREATE PROCEDURE [task].[AddUpdateTicket]
    @id INT = NULL OUTPUT,
    @ticketReference UNIQUEIDENTIFIER = NULL OUTPUT,
    @ticketNumber INT = NULL,
    @title VARCHAR(100) = NULL,
    @description VARCHAR(1000) = NULL,
    @contractReference UNIQUEIDENTIFIER,
    @priority TINYINT,
    @status TINYINT,
    @class VARCHAR(100) = NULL,
    @saved VARCHAR(100) = NULL,
    @cred VARCHAR(100) = NULL,
    @AccountNumber VARCHAR(100) = NULL,
    @Email VARCHAR(100) = NULL,
    @AccountNumber2 VARCHAR(100) = NULL,
    @Negotiator VARCHAR(100) = NULL,
    @offer VARCHAR(100) = NULL,
    @rebuttle VARCHAR(150) = NULL,
    @inquiry BIT = 0,
    @livesupport BIT = 0,
    @AdjustPay BIT = 0,
    @Adjustment BIT = 0,
    @type INT,
    @assignedTo INT = NULL,
    @dueDate DATETIME = NULL,
    @FollowUpDate DATETIME = NULL,
    @NewDate1 DATETIME = NULL,
    @offerId INT = NULL,
    @settlementType TINYINT = NULL,
    @creditorLetter BIT = NULL,
    @clientAuthorization BIT = NULL,
    @clgLawApproval BIT = NULL,
    @loanId INT = NULL,
    @userId INT,
    @Outcome INT = NULL,
    @FeeAmount MONEY = 0.00,
    @Amount MONEY = 0.00,
    @ReserveBalance MONEY = 0.00,
    @RoutingNumber VARCHAR(80) = NULL,
    @PayableTo VARCHAR(80) = NULL,
    @MailTo VARCHAR(80) = NULL,
    @ExpirationDate DATETIME = NULL,
    @SettlementExpirationDate DATETIME = NULL,
    @NextPaymentDate DATETIME = NULL,
    @NewDate2 DATETIME = NULL,
    @LenderPhone VARCHAR(100) = NULL,
    @CheckAmount MONEY = 0.00,
    @NextPaymentAmount MONEY = 0.00,
    @TotalFee MONEY = 0.00,
    @SettlementAmount MONEY = 0.00,
    @3PPPRouting VARCHAR(100) = NULL,
    @3PPPAccount VARCHAR(100) = NULL,
    @DepositMethod VARCHAR(100) = NULL,
    @CblpTicketRef UNIQUEIDENTIFIER = NULL,
    @LenderId INT = NULL,
    @ReturnedDate DATETIME = NULL,
    @tasks [dbo].[ListOfIds] READONLY,
    @ticketRows [dbo].[TicketRowDetail] READONLY,
    @outcomeDate DATETIME = NULL,
    @scheduledFeeId INT = NULL,
    @additionalAmountRows [dbo].[TicketRowDetail] READONLY,
    @originalTicketNo INT = NULL,
    @checkDate DATETIME = NULL,
    @documentType NVARCHAR(50) = NULL,
    @state NCHAR(2) = NULL,
    @bankName NVARCHAR(100) = NULL,
    @cbpRoutingNumber NVARCHAR(100) = NULL,
    @cbpBankAccountNumber NVARCHAR(100) = NULL,
    @3PPPName NVARCHAR(100) = NULL,
    @accountsList [dbo].[TicketAccountDetail] READONLY,
    @originalCreditor NVARCHAR(100) = NULL,
    @currentCreditor NVARCHAR(100) = NULL,
    @isReviewed BIT = 0,
    @IsAllTicketSubTaskCompleted BIT = NULL,
    @IsCoClient BIT = 0,
    @verbalOnly BIT = 0
AS
BEGIN
    DECLARE @contractId INT,
            @contractCompanyId INT,
            @userCompanyId INT,
            @currentDate DATETIME = GETDATE(),
            @trancount INT = @@TRANCOUNT,
            @offerStatusId INT,
            @paymentIntegrationId int = NULL;

    SELECT @contractId = Id,
           @contractCompanyId = CompanyId
    FROM [client].[Contract] WITH (NOLOCK)
    WHERE Reference = @contractReference;
    SELECT @userCompanyId = ParentCompanyId
    FROM [company].GetCompanyIdFromUserId(@userId);

    DECLARE @Orchard BIT,
            @NegotiatorAssignId INT;

    IF [secure].IsSystemUser(@userId) = 0
       AND @userCompanyId <> @contractCompanyId
    BEGIN
        DECLARE @message1 VARCHAR(100)
            = 'Unauthorized access, user [' + CAST(@userId AS VARCHAR(10))
              + '] does not have access to the specified contract [' + CAST(@contractId AS VARCHAR(10)) + '].';
        THROW 51000, @message1, 1;
    END

    BEGIN TRY;
        IF (@trancount = 0)
        BEGIN
            BEGIN TRAN;
        END
        ELSE
        BEGIN
            SAVE TRAN [Add_Upd_Tikt_Trans];
        END

        MERGE [task].[Ticket] AS Target
        USING
        (
            SELECT @id,
                   ISNULL(@ticketNumber, 0),
                   @title,
                   @description,
                   @contractId,
                   @priority,
                   @status,
                   @type,
                   @assignedTo,
                   @dueDate,
                   @userId,
                   @currentDate,
                   @currentDate,
                   @isReviewed,
                   @IsCoClient
        ) AS Source
        (Id, TicketNumber, Title, Descr, ContractId, [Priority], [Status], [Type], AssignedTo, DueDate, CreatedBy, CreatedDate, UpdatedDate, IsReviewed, IsCoClient)
        ON Target.Id = Source.Id
        WHEN NOT MATCHED BY Target THEN
            INSERT
            (
                [TicketNumber],
                [Title],
                [Description],
                [ContractId],
                [Priority],
                [Status],
                [Type],
                [AssignedTo],
                DueDate,
                [CreatedBy],
                CreatedDate,
                UpdatedDate,
                IsCoClient
            )
            VALUES
            ([TicketNumber],
             [Title],
             Descr,
             [ContractId],
             [Priority],
             [Status],
             [Type],
             [AssignedTo],
             DueDate,
             [CreatedBy],
             CreatedDate,
             UpdatedDate,
             IsCoClient
            )
        WHEN MATCHED THEN
            UPDATE SET [Title] = Source.Title,
                       [Priority] = Source.[Priority],
                       [Status] = Source.[Status],
                       [Type] = Source.[Type],
                       [AssignedTo] = Source.[AssignedTo],
                       [DueDate] = Source.[DueDate],
                       [UpdatedDate] = Source.[UpdatedDate],
                       [IsReviewed] = Source.[IsReviewed];

        IF (@id IS NULL) --TICKET ID NULL IF START HERE        
        BEGIN
            SELECT @id = SCOPE_IDENTITY();
            SELECT @ticketReference = Reference
            FROM [task].[Ticket]
            WHERE Id = @id;

            IF (@offerId IS NOT NULL)
            BEGIN
                SELECT distinct
                    @offerId = loan.loanSettlementOffer.id,
                    @offer = loan.loanSettlementOffer.OfferNumber,
                    @AccountNumber = LoanLender.AccountNumber,
                    @currentCreditor = currentLender.Name,
                    @originalCreditor = originalLender.Name
                FROM loan.lender WITH (NOLOCK)
                    INNER JOIN loan.LoanLender WITH (NOLOCK)
                        on loan.Lender.Id = loan.LoanLender.LenderId
                    INNER JOIN loan.Loan WITH (NOLOCK)
                        on loan.LoanLender.LoanId = loan.Loan.Id
                           AND loan.Loan.LoanStatusId = 1
                    INNER JOIN client.Contract WITH (NOLOCK)
                        on loan.Loan.ContractId = client.Contract.Id
                    INNER JOIN loan.LoanSettlement WITH (NOLOCK)
                        on loan.loan.Id = loan.LoanSettlement.LoanId
                    LEFT OUTER JOIN loan.LoanSettlementOffer WITH (NOLOCK)
                        on loan.LoanSettlement.Id = loan.LoanSettlementOffer.SettlementId
                    LEFT OUTER JOIN loan.LoanRepaymentDetails WITH (NOLOCK)
                        on loan.LoanRepaymentDetails.OfferId = loan.LoanSettlementOffer.id
                    INNER JOIN
                    (
                        SELECT MAX(Version) AS Version,
                               LoanLender.LoanId
                        FROM loan.LoanLender WITH (NOLOCK)
                            INNER JOIN loan.Lender WITH (NOLOCK)
                                ON LoanLender.LenderId = Lender.Id
                        WHERE Lender.IsActive = 1
                        GROUP BY LoanId
                    ) AS currentLoanLenderVersion
                        ON currentLoanLenderVersion.LoanId = LoanLender.LoanId
                    INNER JOIN loan.LoanLender AS currentLoanLender WITH (NOLOCK)
                        ON currentLoanLenderVersion.LoanId = currentLoanLender.LoanId
                           AND currentLoanLenderVersion.Version = currentLoanLender.Version
                    INNER JOIN loan.Lender AS currentLender WITH (NOLOCK)
                        ON currentLender.Id = currentLoanLender.LenderId
                    INNER JOIN
                    (
                        SELECT MIN(Version) AS Version,
                               LoanLender.LoanId
                        FROM loan.LoanLender WITH (NOLOCK)
                            INNER JOIN loan.Lender WITH (NOLOCK)
                                ON LoanLender.LenderId = Lender.Id
                        WHERE Lender.IsActive = 1
                        GROUP BY LoanId
                    ) AS originalLoanLenderVersion
                        ON originalLoanLenderVersion.LoanId = LoanLender.LoanId
                    INNER JOIN loan.LoanLender AS originalLoanLender WITH (NOLOCK)
                        ON originalLoanLenderVersion.LoanId = originalLoanLender.LoanId
                           AND originalLoanLenderVersion.Version = originalLoanLender.Version
                    INNER JOIN loan.Lender AS originalLender WITH (NOLOCK)
                        ON originalLender.Id = originalLoanLender.LenderId
                WHERE loan.loanSettlementOffer.id = @offerId;
            END

            IF (@ticketNumber IS NULL)
            BEGIN --TICKET NUMBER NULL IF START HERE        
                UPDATE [task].[Ticket]
                SET TicketNumber = @id
                WHERE Id = @id;
            END

            IF (@type IN ( 112 ))
            BEGIN
                select @assignedTo =
                (
                    select Id
                    from [Identity].[Users]
                    where Email = 'csdepartment@deepartment.com'
                ) -- CS Department User      
            END

            IF (@type IN ( 36, 66 )) --type 36 = Negotiator SAT Review & 66 = Settlement At Risk (N&V or Check Change)      
            BEGIN
                IF (@NextPaymentDate IS NULL)
                BEGIN
                    SELECT @NextPaymentDate = MIN(payment.Date)
                    FROM client.ScheduledLoanRelatedFees payment WITH (NOLOCK)
                        INNER JOIN loan.LoanSettlementOffer offer WITH (NOLOCK)
                            ON offer.Id = payment.OfferId
                    --AND offer.OfferStatusId IN (4, 12) -- ACCEPTED, Accepted_Resettle        
                    WHERE payment.IsLoanRepaymentFee = 1
                          AND payment.StatusId NOT IN ( 19, 18, 12, 6 )
                          and payment.ContractId = @contractId
                          and payment.Date >= DATEADD(dd, 0, DATEDIFF(dd, 0, GETDATE()))
                END

                IF (DATEADD(dd, 0, DATEDIFF(dd, 0, @NextPaymentDate)) = DATEADD(dd, 0, DATEDIFF(dd, 0, GETDATE())))
                BEGIN
                    UPDATE [task].[Ticket]
                    SET Priority = 3
                    WHERE Id = @id;
                END
            END
            SELECT @SettlementExpirationDate = settlementOffer.ExpirationDate,
                   @SettlementAmount = metadata.Amount,
                   @FeeAmount = metadata.Fee
            FROM loan.LoanSettlement settlement WITH (NOLOCK)
                INNER JOIN loan.Loan loan WITH (NOLOCK)
                    ON loan.Id = settlement.LoanId
                LEFT OUTER JOIN [loan].[LoanSettlementOffer] settlementOffer WITH (NOLOCK)
                    ON settlementOffer.SettlementId = settlement.Id
                LEFT OUTER JOIN [loan].[LoanSettlementOfferMetadata] metadata WITH (NOLOCK)
                    ON metadata.OfferId = settlementOffer.Id
                LEFT OUTER JOIN [identity].Users AS createdUser WITH (NOLOCK)
                    ON createdUser.Id = metadata.CreatedBy
                LEFT OUTER JOIN [loan].[SettlementNegotiatorAssignment] settlementAssignment WITH (NOLOCK)
                    ON settlementAssignment.LoanSettlementId = settlement.Id
                       AND settlementAssignment.IsActive = 1
                LEFT OUTER JOIN [loan].[OfferNegotiatorAssignment] offerNegotiatorAssignment WITH (NOLOCK)
                    ON offerNegotiatorAssignment.OfferId = settlementOffer.Id
                       AND offerNegotiatorAssignment.IsActive = 1
            WHERE settlement.LoanId = @loanId
                  and settlementOffer.[OfferStatusId] in ( 4, 5, 2, 7, 6 )
            GROUP BY ExpirationDate,
                     settlementOffer.[Id],
                     settlement.[Id],
                     metadata.Fee,
                     metadata.Amount
            ORDER BY settlementOffer.Id;

            SELECT @DepositMethod = PMT.Name,
                   @paymentIntegrationId = CPI.PaymentIntegrationId
            FROM [client].[ContractPaymentMethod] AS CPM WITH (NOLOCK)
                INNER JOIN [client].[ContractPaymentIntegration] AS CPI WITH (NOLOCK)
                    ON CPM.ContractId = CPI.ContractId
                JOIN [dbo].[PaymentMethodType] PMT WITH (NOLOCK)
                    ON CPM.PaymentMethodTypeId = PMT.Id
            WHERE CPM.ContractId = @contractId;

            SELECT @TotalFee = SUM(fees.[Amount])
            FROM client.ScheduledLoanRelatedFees fees WITH (NOLOCK)
                INNER JOIN loan.LoanSettlementOffer offer WITH (NOLOCK)
                    ON offer.Id = fees.OfferId
                INNER JOIN loan.LoanSettlement settlement WITH (NOLOCK)
                    ON settlement.Id = offer.SettlementId
                INNER JOIN loan.Loan loans WITH (NOLOCK)
                    ON loans.Id = settlement.LoanId
                INNER JOIN loan.LoanLender loanLender WITH (NOLOCK)
                    ON loanLender.LoanId = loans.Id
                       AND loanLender.IsActive = 1
                LEFT OUTER JOIN [company].SettlementTransactionFeeMapping feeMapping WITH (NOLOCK)
                    ON feeMapping.Id = fees.FeeMappingId
            WHERE fees.ContractId = @contractId
                  AND fees.StatusId = 9
                  AND IsLoanRepaymentFee = 0


            -- SELECT @offer = OfferNumber        
            --    FROM loan.LoanSettlementOffer LSO        
            --    INNER JOIN loan.LoanSettlement LS on LSO.SettlementId = LS.id        
            --WHERE LSO.Id = @offerId and LoanId = @loanId        


            IF (@type in ( 4 ))
            BEGIN
                SET @dueDate = @SettlementExpirationDate
            END

            IF (@type in ( 2, 3, 4, 24, 41, 51, 61 ))
            BEGIN
                SELECT @LenderId = LenderId,
                       @AccountNumber = AccountNumber,
                       @cred = Name
                FROM loan.loanlender LL WITH (NOLOCK)
                    inner join loan.lender L WITH (NOLOCK)
                        on LL.LenderId = L.Id
                where LoanId = @loanId
            END

            IF (@type in ( 2, 4 ))
            BEGIN

                select @NegotiatorAssignId = lsom.CreatedBy
                from loan.LoanSettlementOfferMetadata lsom WITH (NOLOCK)
                where lsom.OfferId = @offerId

                UPDATE task.Ticket
                SET Ticket.CreatedBy = @NegotiatorAssignId
                WHERE Ticket.Id = @id
            END

            IF (@Negotiator IS NULL)
            BEGIN
                IF (@offerId IS NULL)
                BEGIN
                    SELECT DISTINCT
                        @Negotiator = negotiatorUser.Name
                    FROM client.Contract WITH (NOLOCK)
                        LEFT OUTER JOIN client.ContractAssignment WITH (NOLOCK)
                            ON client.ContractAssignment.ContractId = client.Contract.Id
                        LEFT OUTER JOIN [identity].Users assignedUsers WITH (NOLOCK)
                            ON assignedUsers.Id = client.ContractAssignment.UserId
                        LEFT OUTER JOIN client.ContractAssignment coas WITH (NOLOCK)
                            ON coas.ContractId = client.Contract.Id
                               AND coas.RoleTypeId = 3
                               AND coas.StatusId = 1
                        LEFT OUTER JOIN [identity].Users negotiatorUser WITH (NOLOCK)
                            ON negotiatorUser.Id = coas.UserId
                        LEFT OUTER JOIN client.ContractAssignment coas2 WITH (NOLOCK)
                            ON coas2.ContractId = client.Contract.Id
                               AND coas2.RoleTypeId = 4
                               AND coas2.StatusId = 1
                        LEFT OUTER JOIN [identity].Users loanNegotiatorUser WITH (NOLOCK)
                            ON loanNegotiatorUser.Id = coas2.UserId
                    WHERE client.contract.Id = @contractId
                END
                ELSE
                BEGIN
                    SELECT @Negotiator = u.Name
                    FROM [Loan].[OfferNegotiatorAssignment] ona WITH (NOLOCK)
                        JOIN [identity].Users u WITH (NOLOCK)
                            ON ona.UserId = u.Id
                    WHERE ona.OfferId = @offerId
                          AND ona.IsActive = 1
                END
            END

            IF (@type in ( 1, 4, 5, 6, 7, 8, 9, 10, 24, 27, 28, 38, 39, 40, 41, 46, 49, 55, 56, 58, 76, 77, 78, 79,
                           111, 112, 115
                         )
               )
            BEGIN
                IF (@type = 49)
                BEGIN
                    DECLARE @feeMappingId int = 0
                    SELECT TOP 1
                        @feeMappingId = FeeMappingId
                    FROM loan.loanrepaymentdetails WITH (NOLOCK)
                    WHERE OfferId = @offerId
                    ORDER BY Id
                    IF (
                           @clgLawApproval = 1
                           AND @paymentIntegrationId = 6 --Higbee Legal Defense Plan      
                           AND @feeMappingId = 52
                       )
                    --When Law Firm Approval is left checked in the modal then ONLY "Law Firm Approval" and 3ppp Higbee Legal Defense Plan and one payment check bu phone             
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        FROM dbo.TicketCategoryTask CT WITH (NOLOCK)
                            INNER JOIN dbo.TicketCategory TC WITH (NOLOCK)
                                ON CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 49
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 277 )
                    END
                END
                Else IF (@type in ( 24 ))
                BEGIN
                    --133 and 139 are the Need Resolved ones that are conditionally created. Modify below and add inside a conditional for the creation of tasks in the AddUpdateTicket stored procedure.        
                    IF (@creditorLetter = 1 AND @clientAuthorization = 1)
                    --When Client Authorization and Creditor letter are left checked in the modal then ONLY "Settlement Letter Received by System" 133 should be listed under the Must Be Completed        
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        FROM dbo.TicketCategoryTask CT WITH (NOLOCK)
                            INNER JOIN dbo.TicketCategory TC WITH (NOLOCK)
                                ON CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 24
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 133, 134, 135, 136, 137, 138, 140, 141, 251 )
                    END

                    IF (@creditorLetter = 1 AND @clientAuthorization = 0)
                    --When only Creditor Letter is left checked in the modal ONLY "Settlement Letter Received by System" 133 should be listed under the Must Be Completed        
                    --No Optional tasks needed        
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 24
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 133 )
                    END

                    IF (@creditorLetter = 0 AND @clientAuthorization = 1)
                    --When only Client Authorization is left checked in the modal then the Must Be Completed: section does not need displayed at all        
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 24
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 134, 135, 136, 137, 138, 140, 141, 251 )
                    END
                    IF (@clgLawApproval = 1)
                    --When Law Firm Approval is left checked in the modal then ONLY "Settlement Letter Received by System"           
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 24
                              AND NeedsResolved IN ( 1 )
                              AND CT.Id IN ( 275 )
                    END
                END
                Else IF (@type in ( 78 ))
                BEGIN
                    IF (@clgLawApproval = 1)
                    --When Law Firm Approval is left checked in the modal then ONLY "Law Firm Approval"                 
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 78
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 122, 123, 124, 125, 126, 142, 143, 250, 276, 281 )
                    END
                    ELSE
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 78
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 122, 123, 124, 125, 126, 142, 143, 250, 281 )
                    END
                END
                --For Loan Estimate Ticket        
                Else if (@type IN ( 38 ))
                BEGIN
                    IF (@clgLawApproval = 1)
                    --When Law Firm Approval is left checked in the modal then ONLY "Law Firm Approval" task should add.        
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 38
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 115, 279 )
                    END
                    ELSE
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 38
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 115 )
                    END
                END
                Else IF (@type in ( 4 ))
                BEGIN
                    if (@clientAuthorization = 0 AND @clgLawApproval = 0)
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 4
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 108 )
                    END
                    ELSE
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               CT.ID,
                               @userId
                        from dbo.TicketCategoryTask CT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on CT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = 4
                              AND NeedsResolved IN ( 0, 1 )
                              AND CT.Id IN ( 104, 105, 106, 107, 108 )
                    END
                END
                ELSE
                BEGIN
                    IF (@type in ( 55, 56, 58 ))
                    BEGIN
                        INSERT INTO [task].[TicketCheckListData]
                        (
                            TicketId,
                            TicketCategoryTaskId,
                            AssignedTo
                        )
                        SELECT @id,
                               TCT.ID,
                               @userId
                        from dbo.TicketCategoryTask TCT WITH (NOLOCK)
                            inner join dbo.TicketCategory TC WITH (NOLOCK)
                                on TCT.TicketCategoryId = TC.Id
                        WHERE TC.TicketTypeId = @type
                              --AND TC.Id IN (SELECT Reference FROM [task].[Ticket] WHERE Id = @id)        
                              AND TCT.Id IN (
                                                Select Id from @tasks
                                            );
                    END
                    ELSE
                    BEGIN
                        Set @feeMappingId = 0
                        SELECT TOP 1
                            @feeMappingId = FeeMappingId
                        FROM loan.loanrepaymentdetails WITH (NOLOCK)
                        WHERE OfferId = @offerId
                        ORDER BY Id

                        IF (
                               @clgLawApproval = 0
                               and @type = 49
                               AND @paymentIntegrationId = 6 --Higbee Legal Defense Plan      
                               AND @feeMappingId = 52
                           )
                        Begin
                            Print ''
                        End
                        Else
                        Begin
                            INSERT INTO [task].[TicketCheckListData]
                            (
                                TicketId,
                                TicketCategoryTaskId,
                                AssignedTo
                            )
                            SELECT @id,
                                   CT.ID,
                                   @userId
                            FROM dbo.TicketCategoryTask CT WITH (NOLOCK)
                                INNER JOIN dbo.TicketCategory TC WITH (NOLOCK)
                                    ON CT.TicketCategoryId = TC.Id
                            WHERE TC.TicketTypeId = @type

                        End
                    END --ELSE        
                END --ELSE        
            END -- IF        



            INSERT INTO [task].TicketData
            (
                Id,
                Class,
                Saved,
                Inquiry,
                LiveSupport,
                RebuttleReason,
                CurrentCreditor,
                OriginalCreditor,
                Negotiator,
                NewDate1,
                AccountNumber,
                FollowUpDate,
                OfferNumber,
                OfferId,
                settlementType,
                CreditorLetter,
                ClientAuthorization,
                CLGLawApproval,
                LoanId,
                OutcomeId,
                TrackingNumber,
                RoutingNumber,
                PayableTo,
                MailTo,
                ExpirationDate,
                SettlementExpirationDate,
                NextPaymentDate,
                FeeAmount,
                NewDate2,
                AccountNumber2,
                Amount,
                LenderPhone,
                AdjustPay,
                Adjustment,
                SettlementAmount,
                TotalFee,
                CheckAmount,
                DepositMethod,
                LenderId,
                ReturnedDate,
                OutcomeDate,
                ScheduledFeeId,
                OriginalTicketNo,
                CheckDate,
                DocumentType,
                State,
                BankName,
                CBPBankAccountNumber,
                CBPRoutingNumber,
                [3PPPName],
                VerbalOnly
            )
            VALUES
            (@id,
             @class,
             @saved,
             @inquiry,
             @livesupport,
             @rebuttle,
             @currentCreditor,
             @originalCreditor,
             @Negotiator,
             @NewDate1,
             @AccountNumber,
             @FollowUpDate,
             @offer,
             @offerId,
             @settlementType,
             @creditorLetter,
             @clientAuthorization,
             @clgLawApproval,
             @loanId,
             @Outcome,
             @RoutingNumber,
             @RoutingNumber,
             @PayableTo,
             @MailTo,
             @ExpirationDate,
             @SettlementExpirationDate,
             @NextPaymentDate,
             @FeeAmount,
             @NewDate2,
             @AccountNumber2,
             @Amount,
             @LenderPhone,
             @AdjustPay,
             @Adjustment,
             @SettlementAmount,
             @TotalFee,
             @CheckAmount,
             @DepositMethod,
             @LenderId,
             @ReturnedDate,
             @outcomeDate,
             @scheduledFeeId,
             @originalTicketNo,
             @checkDate,
             @documentType,
             @state,
             @bankName,
             @cbpBankAccountNumber,
             @cbpRoutingNumber,
             @3PPPName,
             @verbalOnly
            );

            INSERT INTO [task].[TicketRowDetail]
            (
                TicketId,
                OfferId,
                PaymentId,
                IsCompleted,
                UnableToComplete
            )
            SELECT @id,
                   OfferId,
                   PaymentId,
                   IsCompleted,
                   UnableToComplete
            FROM @ticketRows;

            INSERT INTO [task].[TicketRowAmountNeedDetail]
            (
                TicketId,
                [Date],
                Amount
            )
            SELECT @id,
                   [Date],
                   Amount
            FROM @additionalAmountRows;

            INSERT INTO [task].[TicketAccountDetail]
            (
                TicketId,
                Creditor,
                AccountLast4,
                Balance,
                LoanId
            )
            SELECT @id,
                   Creditor,
                   AccountLast4,
                   Balance,
                   LoanId
            FROM @accountsList

            IF (@type = 20)
            BEGIN
                EXEC [task].[AddNCAMidMonth] @contractId = @contractId,
                                             @contractReference = @contractReference
            END

            IF (@type = 57)
            BEGIN
                EXEC [client].[AddContractTags] @reference = @contractReference,
                                                @tagId = 134
            END

            IF (@type IN ( 2, 25 ))
            BEGIN
                EXEC [task].[AddHoldTag] @ContractId = @ContractId,
                                         @ContractReference = @ContractReference,
                                         @ticketReference = @ticketReference,
                                         @loanId = @loanId
            END
        END --TICKET NUMBER NULL END START HERE        
        ELSE
        BEGIN
            UPDATE [task].TicketData
            SET Class = @class,
                Saved = @saved,
                Inquiry = @inquiry,
                LiveSupport = @livesupport,
                RebuttleReason = @rebuttle,
                Negotiator = @Negotiator,
                FollowUpDate = @FollowUpDate,
                LoanId = @loanId,
                CreditorLetter = @creditorLetter,
                ClientAuthorization = @clientAuthorization,
                CLGLawApproval = @clgLawApproval,
                OutcomeId = @Outcome,
                TrackingNumber = @RoutingNumber,
                PayableTo = @PayableTo,
                MailTo = @MailTo,
                ExpirationDate = @ExpirationDate,
                NewDate1 = @NewDate1,
                SettlementExpirationDate = @SettlementExpirationDate,
                NextPaymentDate = @NextPaymentDate,
                FeeAmount = @FeeAmount,
                Amount = @Amount,
                NewDate2 = @NewDate2,
                AdjustPay = @AdjustPay,
                Adjustment = @Adjustment,
                RoutingNumber = @RoutingNumber,
                AccountNumber2 = @AccountNumber2,
                ReturnedDate = @ReturnedDate,
                OutcomeDate = @outcomeDate,
                CheckDate = @checkDate,
                DocumentType = @documentType,
                State = @state,
                BankName = @bankName,
                CBPBankAccountNumber = @cbpBankAccountNumber,
                CBPRoutingNumber = @cbpRoutingNumber,
                [3PPPName] = @3PPPName,
                IsAllTicketSubTaskCompleted = Case
                                                  When IsNull(IsAllTicketSubTaskCompleted, 0) = 1 Then
                                                      1
                                                  else
                                                      @IsAllTicketSubTaskCompleted
                                              End
            WHERE Id = @id;

            declare @taskCount Int;
            Select @taskCount = COUNT(t.Id)
            from task.TicketCheckListData t WITH (NOLOCK)
            where t.TicketId =
            (
                SELECT Id
                FROM task.Ticket WITH (NOLOCK)
                WHERE Reference = @ticketReference
            )
                  and t.TicketCategoryTaskId in (
                                                    select Id from @tasks
                                                );
            IF (@type in ( 55, 56 ) and @taskCount = 0)
            BEGIN
                Delete from [task].[TicketCheckListData]
                where TicketId =
                (
                    select Id
                    from task.Ticket WITH (NOLOCK)
                    Where Reference = @ticketReference
                )

                INSERT INTO [task].[TicketCheckListData]
                (
                    TicketId,
                    TicketCategoryTaskId,
                    AssignedTo
                )
                SELECT @id,
                       TCT.ID,
                       @userId
                from dbo.TicketCategoryTask TCT WITH (NOLOCK)
                    inner join dbo.TicketCategory TC WITH (NOLOCK)
                        on TCT.TicketCategoryId = TC.Id
                WHERE TC.TicketTypeId = @type
                      --AND TC.Id IN (SELECT Reference FROM [task].[Ticket] WHERE Id = @id)        
                      AND TCT.Id IN (
                                        Select Id from @tasks
                                    );
            END
        END
        -- Add Remove Pending RTA tag if ticket is RTA ticket      
        IF (@type in ( 110 ))
        Begin
            EXEC [Client].[AddRemovePendingRTATag] @id, @contractReference, @status
        End
        IF (@type = 1 or @type = 30)
        BEGIN
            exec [task].[FundingStatusTicket] @contractReference = @contractReference,
                                              @ticketId = @id
        END

        IF (@type IN ( 107 ) AND @status = 7)
        BEGIN
            Update [task].[Ticket]
            SET ResolvedBy = @userid,
                ResolvedDate = GETDATE()
            WHERE Id = @id;
        END

        IF (@type = 108)
        BEGIN
            exec [task].[AddUpdateCBLPData] @TicketId = @id,
                                            @contractId = @contractId,
                                            @PaymentType = @rebuttle,
                                            @PaymentResolution = @Outcome,
                                            @CBLPProgram = @class,
                                            @AccountNumber = @AccountNumber,
                                            @Creditor = @currentCreditor,
                                            @AlternateBank = @inquiry,
                                            @RoutingNumber = @RoutingNumber,
                                            @BankAccountNumber = @AccountNumber2,
                                            @WithdrawalDate = @dueDate,
                                            @StatusUpdate = @NewDate2;
        END

        IF (@type = 109)
        BEGIN
            exec [task].[AddUpdateCBLPData] @TicketId = @id,
                                            @contractId = @contractId,
                                            @PaymentType = @rebuttle,
                                            @PaymentResolution = @Outcome,
                                            @CBLPProgram = @class,
                                            @AccountNumber = @AccountNumber,
                                            @Creditor = @currentCreditor,
                                            @AlternateBank = @inquiry,
                                            @RoutingNumber = @RoutingNumber,
                                            @BankAccountNumber = @AccountNumber2,
                                            @WithdrawalDate = @dueDate,
                                            @StatusUpdate = @NewDate2;

            IF @Outcome = 32
            BEGIN
                DECLARE @ticketId INT;
                SELECT @ticketId = Id
                FROM task.Ticket WITH (NOLOCK)
                WHERE Reference = @ticketReference;
                UPDATE client.CBLP
                SET PaymentResolution = @Outcome
                WHERE TicketId = @ticketId;

                SELECT @ticketId = Id
                FROM task.Ticket WITH (NOLOCK)
                WHERE Reference = @CblpTicketRef;
                UPDATE client.CBLP
                SET PaymentResolution = 35
                WHERE TicketId = @ticketId;

                UPDATE task.TicketData
                SET task.TicketData.OutcomeId = 35,
                    task.TicketData.NewDate2 = GETDATE()
                FROM task.Ticket WITH (NOLOCK)
                    INNER JOIN task.TicketData WITH (NOLOCK)
                        on task.Ticket.Id = task.TicketData.Id
                WHERE task.Ticket.Reference = @CblpTicketRef;
            END
        END

        IF (@type = 54)
        BEGIN
            exec [task].[UpdateReserveBalance] @contractId = @contractId,
                                               @ReserveBalance = @ReserveBalance
        END

        UPDATE task.Ticket
        SET task.Ticket.title = dbo.TicketType.Name,
            task.ticket.AssignedTo = @assignedTo
        FROM dbo.TicketType
            Inner join task.ticket
                on dbo.TicketType.Id = task.ticket.Type
            Inner join task.ticketData
                on task.ticket.Id = task.ticketData.Id
        WHERE Type = dbo.TicketType.Id
              and task.ticketdata.Id = @id;

        IF (@status = 7) -- dbo.TicketStatus.Name = Resolved        
        BEGIN
            UPDATE [task].[Ticket]
            SET ResolvedDate = @currentDate
            WHERE Ticket.Id = @id;
            IF (@contractReference IS NOT NULL)
            BEGIN
                SELECT @offerStatusId = LoanSettlementOffer.OfferStatusId
                FROM loan.lender WITH (NOLOCK)
                    INNER JOIN loan.LoanLender WITH (NOLOCK)
                        on loan.Lender.Id = loan.LoanLender.LenderId
                    INNER JOIN loan.Loan WITH (NOLOCK)
                        on loan.LoanLender.LoanId = loan.Loan.Id
                           AND loan.Loan.LoanStatusId = 1
                    INNER JOIN client.Contract WITH (NOLOCK)
                        on loan.Loan.ContractId = client.Contract.Id
                    INNER JOIN loan.LoanSettlement WITH (NOLOCK)
                        on loan.loan.Id = loan.LoanSettlement.LoanId
                    INNER JOIN loan.LoanSettlementOffer WITH (NOLOCK)
                        on loan.LoanSettlement.Id = loan.LoanSettlementOffer.SettlementId
                WHERE loan.loanSettlementOffer.id = @offerId

                IF (@offerStatusId = 5)
                BEGIN
                    exec [loan].[UpdateSettlementOfferStatus] @reference = @contractReference,
                                                              @offerId = @offerId,
                                                              @statusId = 6
                END
            END
        END

        IF (@trancount = 0)
        BEGIN
            COMMIT TRAN;
        END
    END TRY
    BEGIN CATCH;
        DECLARE @error INT,
                @message VARCHAR(4000),
                @xstate INT;
        SELECT @error = ERROR_NUMBER(),
               @message = ERROR_MESSAGE(),
               @xstate = XACT_STATE();

        IF (@xstate = -1)
        BEGIN
            ROLLBACK;
        END
        IF (@xstate = 1 AND @trancount = 0)
        BEGIN
            ROLLBACK;
        END
        IF (@xstate = 1 AND @trancount > 0)
        BEGIN
            ROLLBACK TRAN [Add_Upd_Tikt_Trans];
        END

        RAISERROR('[task].[AddUpdateTicket]: %d: %s', 16, 1, @error, @message);
    END CATCH;

END


--Extra part FOR DEMO         

IF (@email = 'NoClientEmail@centuryss.com' AND @type = 57)
BEGIN
    SET @id = NULL;
    BEGIN
        MERGE [task].[Ticket] AS Target
        USING
        (
            SELECT @id,
                   ISNULL(@ticketNumber, 0),
                   @title,
                   @contractId,
                   @priority,
                   @status,
                   12,
                   @assignedTo,
                   @dueDate,
                   @userId,
                   @currentDate,
                   @currentDate
        ) AS Source
        (Id, TicketNumber, Title, ContractId, [Priority], [Status], [Type], AssignedTo, DueDate, CreatedBy, CreatedDate, UpdatedDate)
        ON Target.Id = Source.Id
        WHEN NOT MATCHED BY TARGET THEN
            INSERT
            (
                [TicketNumber],
                [Title],
                [ContractId],
                [Priority],
                [Status],
                [Type],
                [AssignedTo],
                DueDate,
                [CreatedBy],
                CreatedDate,
                UpdatedDate
            )
            VALUES
            ([TicketNumber],
             'Mail me',
             [ContractId],
             [Priority],
             [Status],
             12 ,
             635,
             DueDate,
             [CreatedBy],
             CreatedDate,
             UpdatedDate
            );

        SELECT @id = SCOPE_IDENTITY();

        SELECT @ticketReference = Reference
        FROM [task].[Ticket]
        WHERE Id = @id;
        IF (@ticketNumber IS NULL)
        BEGIN
            DECLARE @nextId2 INT = @id;
            SELECT @nextId2 = X.SeedValue
            FROM
            (
                SELECT ticket.Id,
                       ROW_NUMBER() OVER (PARTITION BY CompanyId ORDER BY ticket.Id) SeedValue
                FROM [task].[Ticket] ticket
                    INNER JOIN client.Contract c
                        ON c.Id = ticket.ContractId
                WHERE c.CompanyId = @contractCompanyId
            ) X
            WHERE Id = @id;

            UPDATE [task].[Ticket]
            SET TicketNumber = @nextId2
            WHERE Id = @id;

            INSERT INTO [task].TicketData
            (
                Id,
                Class,
                Saved,
                Inquiry,
                LiveSupport,
                RebuttleReason,
                CurrentCreditor,
                OriginalCreditor,
                Negotiator,
                NewDate1,
                AccountNumber,
                FollowUpDate,
                OfferNumber,
                OfferId,
                settlementType,
                CreditorLetter,
                ClientAuthorization,
                CLGLawApproval,
                LoanId,
                OutcomeId,
                TrackingNumber,
                RoutingNumber,
                PayableTo,
                MailTo,
                ExpirationDate,
                SettlementExpirationDate,
                NextPaymentDate,
                FeeAmount,
                NewDate2,
                AccountNumber2,
                Amount,
                [3PPPName]
            )
            VALUES
            (@id,
             'Contract',
             @saved,
             @inquiry,
             @livesupport,
             @rebuttle,
             @cred,
             @originalCreditor,
             @Negotiator,
             @newDate1,
             @accountNumber,
             @followUpDate,
             @offer,
             @offerId,
             @settlementType,
             @creditorLetter,
             @clientAuthorization,
             @clgLawApproval,
             @loanId,
             @outcome,
             @RoutingNumber,
             @RoutingNumber,
             @payableTo,
             @mailTo,
             @expirationDate,
             @settlementExpirationDate,
             @nextPaymentDate,
             @feeAmount,
             @newDate2,
             @accountNumber2,
             @amount,
             @3PPPName
            );
        END;
    END;
END;