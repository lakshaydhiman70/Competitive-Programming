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


SELECT * FROM (
	select a.friendlyid, b.IsPrimary, e.Name, d.Number
	from client.contract a
	inner join client.contractApplicant b on a.id = b.contractid
	inner join client.ClientPhone c on b.clientid = c.clientid
	inner join comn.Phone d on d.id = c.phoneid
	inner join phonetype e on e.id = c.phonetypeid
	where a.friendlyId = 99999654
) AS ClientPhoneData

PIVOT
(
	MAX(Number)
	For Name IN (Work,Cell)
    
) AS PivotTable
