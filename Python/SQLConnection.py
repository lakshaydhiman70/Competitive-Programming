import pyodbc

connection_string = "Driver={SQL Server Native Client 11.0};Server=35.80.131.226;Database=atlas_pre-dev;UID=finxera;PWD=finxera;"

try:
    conn = pyodbc.connect(connection_string)
    cursor = conn.cursor()
    query = """SELECT top 10 * FROM client.contract where friendlyid = ?"""
    params = ["999999107"]
	
    cursor.execute(query, params)

    for row in cursor:
        print(row)


except Exception as e:
    print(f"An error occurred: {e}")

finally:
    conn.close()