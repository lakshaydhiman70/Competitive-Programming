import json
import pymongo
from pymongo import MongoClient

def handler(event, context):
    try:
        # Replace with your actual MongoDB connection string
        client = MongoClient(mongo_uri = "mongodb+srv://lakshaydhiman70:<password>@cluster0.hi4dknc.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0")
        db = client.lakshaydb
        collection = db.Users

        
        # Example of finding a document
        result = collection.find_one({"name": "John"})
        
        return {
            'statusCode': 200,
            'body': json.dumps(result, default=str)  # Convert ObjectId to string
        }

    except Exception as e:
        return {
            'statusCode': 500,
            'body': str(e)
        }
