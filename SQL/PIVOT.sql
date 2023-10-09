SELECT * FROM 
(
	SELECT PT.Name, LP.Number From Loan.LenderPhone LP
	JOIN PhoneType PT ON PT.Id = LP.PhoneTypeId
	Where LenderId = 8

) AS LenderPhoneData

PIVOT
(
	MAX(Number)
	For Name IN (Work,Fax)
    
) AS PivotTable
