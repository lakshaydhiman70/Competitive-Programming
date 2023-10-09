WITH CTE_DATA(MaxAmount, MinDate) AS (
	SELECT Max(CPD.Amount) AS MaxAmount, Min(CPD.Date)AS MinDate FROM Client.Contract
	INNER JOIN  client.ContractPaymentPlan CPP ON CPP.ContractId = Contract.Id
	INNER JOIN client.ContractPaymentDetail CPD ON CPD.ContractPaymentPlanId = CPP.Id
	GROUP BY (CONTRACT.Friendlyid)
)

select * from CTE_DATA where maxamount > 1000


--It is just used to create a temp table on the run time.