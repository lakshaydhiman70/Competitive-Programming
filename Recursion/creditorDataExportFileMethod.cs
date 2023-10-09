namespace PradMan.GravityX2.WebApi.Controllers.Lender
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Net;
    using System.Net.Http;
    using System.Net.Http.Headers;
    using System.Runtime.InteropServices;
    using System.Threading.Tasks;
    using System.Web.Http;
    using System.Web.Http.Description;

    using AutoMapper;

    using log4net;
    using Microsoft.Office.Interop.Excel;
    using OfficeOpenXml;
    using PradMan.GravityX2.Core;
    using PradMan.GravityX2.Entities;
    using PradMan.GravityX2.Entities.SearchCriteria;
    using PradMan.GravityX2.WebApi.Framework;
    using PradMan.GravityX2.WebApi.Models;
    using static System.Net.Mime.MediaTypeNames;
    using Application = System.Net.Mime.MediaTypeNames.Application;

    [Authorize]
    public class LenderDocumentsController : ApiControllerBase
    {
        /// <summary>
        /// The lender summary manager.
        /// </summary>
        private readonly ILenderManager lenderManager;

        /// <summary>
        /// The mapper
        /// </summary>
        private readonly IMapper mapper = GlobalSettings.Current.MapperConfiguration.CreateMapper();

        /// <summary>
        /// Initializes a new instance of the <see cref="LenderDocumentsController"/> class.
        /// </summary>
        public LenderDocumentsController()
            : base(LogManager.GetLogger(typeof(LenderDocumentsController)))
        {
            this.lenderManager = LenderManagerFactory.GetInstance();
        }

        /// <summary>
        /// Uploads the document.
        /// </summary>
        /// <returns>
        ///   <see cref="Task" />
        /// </returns>
        [Route("api/lender/document")]
        [HttpPost]
        public async Task<HttpResponseMessage> Post()
        {
            try
            {
                if (!this.Request.Content.IsMimeMultipartContent())
                {
                    throw new HttpResponseException(HttpStatusCode.UnsupportedMediaType);
                }
                var attachment = await this.Request.Content.ParseMultipartAttatchmentsAsync();

                await lenderManager.addUpdateCreditorCsv(attachment.Bytes, this.CurrentUser);

                return this.Request.CreateResponse(HttpStatusCode.OK);
            }
            catch (Exception ex)
            {
                return this.Request.CreateErrorResponse(HttpStatusCode.InternalServerError, ex.Message);
            }
        }

        [Route("api/lender/document")]
        [HttpGet]
        public async Task<HttpResponseMessage> Get()
        {
            try
            {
                
                //var attachment = await this.Request.Content.ParseMultipartAttatchmentsAsync();

                //await lenderManager.ExportToExcel();

                return this.Request.CreateResponse(HttpStatusCode.OK);
            }
            catch (Exception ex)
            {
                return this.Request.CreateErrorResponse(HttpStatusCode.InternalServerError, ex.Message);
            }
        }

        [HttpPost]
        [Route("api/excelexport")]
        public async Task<HttpResponseMessage> ExportToExcel(LenderSearchCriteriaModel searchCriteriaModel)
        {
            try
            {
                // Set the LicenseContext to NonCommercial
                ExcelPackage.LicenseContext = LicenseContext.NonCommercial;

                // Retrieve data from your backend or any other data source
                //List<YourDataModel> data = GetData();

                // Create a new Excel package
                using (ExcelPackage package = new ExcelPackage())
                {
                    // Create a new worksheet
                    ExcelWorksheet worksheet = package.Workbook.Worksheets.Add("Sheet1");

                    // Write column headers
                    worksheet.Cells[1, 1].Value = "Cr ID #";
                    worksheet.Cells[1, 2].Value = "Name";
                    worksheet.Cells[1, 3].Value = "AlsoKnownAs";
                    worksheet.Cells[1, 4].Value = "Creditor Type";
                    worksheet.Cells[1, 5].Value = "Contact Preference";
                    worksheet.Cells[1, 6].Value = "Contact Name";
                    worksheet.Cells[1, 7].Value = "Email";
                    worksheet.Cells[1, 8].Value = "Check Payable to:";
                    worksheet.Cells[1, 9].Value = "Address1";
                    worksheet.Cells[1, 10].Value = "Address2";
                    worksheet.Cells[1, 11].Value = "City";
                    worksheet.Cells[1, 12].Value = "State";
                    worksheet.Cells[1, 13].Value = "Zip";
                    worksheet.Cells[1, 14].Value = "Phone Number";
                    worksheet.Cells[1, 15].Value = "Fax #";
                    worksheet.Cells[1, 16].Value = "Avg. Settlement Length";
                    worksheet.Cells[1, 17].Value = "Avg. Settlement %";
                    worksheet.Cells[1, 18].Value = "Cr Settlement Range Low";
                    worksheet.Cells[1, 19].Value = "CR Settlement Range High";
                    worksheet.Cells[1, 20].Value = "CSS Settlement Range Low";
                    worksheet.Cells[1, 21].Value = "CSS Settlment Range High";
                    worksheet.Cells[1, 22].Value = "Cr. Min Payment";
                    worksheet.Cells[1, 23].Value = "CSS Min Payment";
                    worksheet.Cells[1, 24].Value = "Proposal Letter Req";
                    worksheet.Cells[1, 25].Value = "Auth Before Letter";
                    worksheet.Cells[1, 26].Value = "30 Day Post Date";
                    worksheet.Cells[1, 27].Value = "Scrub Creditor";
                    worksheet.Cells[1, 28].Value = "Walkthrough Req";
                    worksheet.Cells[1, 29].Value = "Conference Call Req";
                    worksheet.Cells[1, 30].Value = "Template Name";
                    worksheet.Cells[1, 31].Value = "Charge Off";
                    worksheet.Cells[1, 32].Value = "LOA Date";
                    worksheet.Cells[1, 33].Value = "LOA Preference";
                    worksheet.Cells[1, 34].Value = "Preferred Payment Method oldCFT";
                    worksheet.Cells[1, 35].Value = "All Available Payment Methods oldCFT";
                    worksheet.Cells[1, 36].Value = "Preferred Payment Method GCS";
                    worksheet.Cells[1, 37].Value = "All Available Payment Methods GCS";
                    worksheet.Cells[1, 38].Value = "Preferred Payment Method Self Saver";
                    worksheet.Cells[1, 39].Value = "All Available Payment Method Self Saver";
                    worksheet.Cells[1, 40].Value = "Preferred Payment Method NewCFT";
                    worksheet.Cells[1, 41].Value = "All Available Payment Methods NewCFT";
                    worksheet.Cells[1, 42].Value = "Preferred Payment Method CLG";
                    worksheet.Cells[1, 43].Value = "All Available Payment Methods CLG";
                    worksheet.Cells[1, 44].Value = "Bulk CBP";
                    worksheet.Cells[1, 45].Value = "Bulk Offer Sheet";
                    worksheet.Cells[1, 46].Value = "Restructure";
                    worksheet.Cells[1, 47].Value = "Orchard";
                    worksheet.Cells[1, 48].Value = "CFT CBP List";
                    worksheet.Cells[1, 49].Value = "CFTPAYEEID";
                    worksheet.Cells[1, 50].Value = "CFTCLGID";
                    worksheet.Cells[1, 51].Value = "GCS Direct Pay Payee ID";
                    worksheet.Cells[1, 52].Value = "GCS DRC Payee ID";
                    worksheet.Cells[1, 53].Value = "RetailList";
                    worksheet.Cells[1, 54].Value = "Tier";
                    // Add more columns as needed
                    var data = new List<string> { "674654535476464", "5754634346744574747", "87686582658632"};

                    var lenders = await this.lenderManager.SearchAsync(this.mapper.Map<LenderCriteria>(searchCriteriaModel), this.CurrentUser);
                    // Write data rows
                    int rowIndex = 2;
                    foreach (var lender in lenders)
                    {
                        worksheet.Cells[rowIndex, 1].Value = "098765432345678908765432456789";
                        worksheet.Cells[rowIndex, 2].Value = lender.Name;
                        worksheet.Cells[rowIndex, 3].Value = lender.AlsoKnownAs;
                        worksheet.Cells[rowIndex, 4].Value = lender.Name;
                        worksheet.Cells[rowIndex, 5].Value = lender.Name;
                        worksheet.Cells[rowIndex, 7].Value = lender.Emails.FirstOrDefault().Address;
                        worksheet.Cells[rowIndex, 8].Value = lender.Emails.FirstOrDefault().Address;
                        worksheet.Cells[rowIndex, 9].Value = lender.Addresses.FirstOrDefault().Address1;
                        worksheet.Cells[rowIndex, 10].Value = lender.Addresses.FirstOrDefault().Address2;
                        worksheet.Cells[rowIndex, 11].Value = lender.Addresses.FirstOrDefault().City;
                        worksheet.Cells[rowIndex, 12].Value = lender.Addresses.FirstOrDefault().State;
                        worksheet.Cells[rowIndex, 13].Value = lender.Addresses.FirstOrDefault().Zip;
                        worksheet.Cells[rowIndex, 14].Value = lender.Phones.Where(x=> x.Type == PhoneType.Work).FirstOrDefault()==null?"": lender.Phones.Where(x => x.Type == PhoneType.Work).FirstOrDefault().Number;
                        worksheet.Cells[rowIndex, 15].Value = lender.Phones.Where(x => x.Type == PhoneType.Fax).FirstOrDefault() == null ? "" : lender.Phones.Where(x => x.Type == PhoneType.Work).FirstOrDefault().Number;
                        worksheet.Cells[rowIndex, 16].Value = lender.AverageSettLength;
                        worksheet.Cells[rowIndex, 17].Value = lender.SettlementPercentage;
                        worksheet.Cells[rowIndex, 18].Value = lender.SettRangeCrLow;
                        worksheet.Cells[rowIndex, 19].Value = lender.SettRangeCrHigh;
                        worksheet.Cells[rowIndex, 20].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 21].Value = lender.SettRangeCSSHigh;
                        worksheet.Cells[rowIndex, 22].Value = lender.MinPaymentAmtCr;
                        worksheet.Cells[rowIndex, 23].Value = lender.MinPaymentAmtCSS;
                        worksheet.Cells[rowIndex, 24].Value = lender.chkProposalLetterReq;
                        worksheet.Cells[rowIndex, 25].Value = lender.chkAuthBeforeLetter;
                        worksheet.Cells[rowIndex, 26].Value = lender.chkThirtyDayPostDate;
                        worksheet.Cells[rowIndex, 27].Value = lender.chkScrubList;
                        worksheet.Cells[rowIndex, 28].Value = lender.chkWalkthroughReq;
                        worksheet.Cells[rowIndex, 29].Value = lender.chkConferenceCallReq;
                        worksheet.Cells[rowIndex, 30].Value = lender.EmailTemplateName;
                        worksheet.Cells[rowIndex, 31].Value = lender.ChargeOffDate;
                        worksheet.Cells[rowIndex, 32].Value = lender.LOADate;
                        worksheet.Cells[rowIndex, 33].Value = lender.LOAPref;
                        worksheet.Cells[rowIndex, 34].Value = getPrimaryPaymentType(lender.Integrations, 3);
                        worksheet.Cells[rowIndex, 35].Value = getPaymentTypes(lender.Integrations, 3);
                        worksheet.Cells[rowIndex, 36].Value = getPrimaryPaymentType(lender.Integrations, 2);
                        worksheet.Cells[rowIndex, 37].Value = getPaymentTypes(lender.Integrations, 2);
                        worksheet.Cells[rowIndex, 38].Value = getPrimaryPaymentType(lender.Integrations, 4);
                        worksheet.Cells[rowIndex, 39].Value = getPaymentTypes(lender.Integrations, 4);
                        worksheet.Cells[rowIndex, 40].Value = getPrimaryPaymentType(lender.Integrations, 5);
                        worksheet.Cells[rowIndex, 41].Value = getPaymentTypes(lender.Integrations, 5);
                        worksheet.Cells[rowIndex, 42].Value = getPrimaryPaymentType(lender.Integrations, 6);
                        worksheet.Cells[rowIndex, 43].Value = getPaymentTypes(lender.Integrations, 6);
                        worksheet.Cells[rowIndex, 44].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 45].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 46].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 47].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 48].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 49].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 50].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 51].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 52].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 53].Value = lender.SettRangeCSSLow;
                        worksheet.Cells[rowIndex, 54].Value = lender.SettRangeCSSLow;
                        // Set values for other columns
                        rowIndex++;
                    }

                    // Convert the Excel package to a byte array
                    byte[] fileBytes = package.GetAsByteArray();

                    // Create a response message
                    HttpResponseMessage response = new HttpResponseMessage(HttpStatusCode.OK);

                    // Set the content of the response as the Excel file
                    response.Content = new ByteArrayContent(fileBytes);

                    // Set the content type header
                    response.Content.Headers.ContentType = new System.Net.Http.Headers.MediaTypeHeaderValue("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

                    // Set the file name for the response
                    response.Content.Headers.ContentDisposition = new System.Net.Http.Headers.ContentDispositionHeaderValue("attachment");
                    response.Content.Headers.ContentDisposition.FileName = "SearchLenders.xlsx";

                    return response;
                }
            }
            catch (Exception ex)
            {
                // Handle any exceptions or error conditions
                return Request.CreateErrorResponse(HttpStatusCode.InternalServerError, ex.Message);
            }
        }

        public string getPrimaryPaymentType(ICollection<LenderIntegration> lenderIntegrations, int paymentProcessorId)
        {
            var lenderIntegrationData = lenderIntegrations.Where(x=> x.IntegrationId == paymentProcessorId).FirstOrDefault();
            var data = string.Empty;
            if (lenderIntegrationData != null && lenderIntegrationData.AcceptedPaymentTypes.Where(x => x.IsPrimary == 1).Any())
            {
                data = lenderIntegrationData.AcceptedPaymentTypes.Where(x => x.IsPrimary == 1).FirstOrDefault().Description;
            }
            return data;
        }

        public string getPaymentTypes(ICollection<LenderIntegration> lenderIntegrations, int paymentProcessorId)
        {
            var lenderIntegrationData = lenderIntegrations.Where(x => x.IntegrationId == paymentProcessorId).FirstOrDefault();
            var data = string.Empty;
            if (lenderIntegrationData != null && lenderIntegrationData.AcceptedPaymentTypes.Where(x => x.IsPrimary == 0).Any())
            {
                data = string.Join("/", lenderIntegrationData.AcceptedPaymentTypes.Where(x => x.IsPrimary == 0).Select(s => s.Description));
            }
            return data;
        }
    }
}
