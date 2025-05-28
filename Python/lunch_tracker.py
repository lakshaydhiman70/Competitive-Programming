import pymongo
from datetime import datetime

# Replace the placeholder values with your actual MongoDB Atlas credentials
username = "lakshaydhiman70"
password = "cT6WGlUJ5g4I9zA6"
cluster_url = "your_cluster_url"
database_name = "lunch_tracker"
collection_name = "daily_payments"

# MongoDB Atlas connection string
mongo_uri = "mongodb+srv://lakshaydhiman70:<password>@cluster0.hi4dknc.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"

# Connect to MongoDB Atlas
mongo_client = pymongo.MongoClient(mongo_uri)
db = mongo_client[database_name]
collection = db[collection_name]

def add_payment(date, name, amount, payment_status, notes=""):
    payment_data = {
        "date": datetime.strptime(date, "%Y-%m-%d"),
        "name": name,
        "amount": amount,
        "payment_status": payment_status,
        "notes": notes
    }
    
    collection.insert_one(payment_data)
    print(f"Payment data for {name} on {date} added successfully.")

# Example data to add
payments = [
    {"date": "2024-05-01", "name": "Alice", "amount": 10, "payment_status": "Paid"},
    {"date": "2024-05-01", "name": "Bob", "amount": 10, "payment_status": "Unpaid", "notes": "Will pay soon"},
    {"date": "2024-05-01", "name": "Charlie", "amount": 10, "payment_status": "Paid"},
    {"date": "2024-05-01", "name": "Dave", "amount": 10, "payment_status": "Unpaid", "notes": "Out of office"},
]

# Add example payments to MongoDB Atlas
for payment in payments:
    add_payment(payment["date"], payment["name"], payment["amount"], payment["payment_status"], payment.get("notes", ""))

# To fetch and display all payment records
def fetch_all_payments():
    all_payments = collection.find()
    for payment in all_payments:
        print(payment)

# Fetch and display payments
fetch_all_payments()
