import schedule
import time

def daily_task():
    # Your daily task code goes here
    print("This is a daily task that runs at 10:00 AM")

# Schedule the daily task to run at 10:00 AM every day
schedule.every().day.at("15:10").do(daily_task)

while True:
    # Run pending scheduled tasks
    schedule.run_pending()
    # Wait for 1 minute before checking again
    time.sleep(60)
