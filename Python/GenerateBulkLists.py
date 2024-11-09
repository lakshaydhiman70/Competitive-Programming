from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# Launch the browser
driver = webdriver.Chrome()  # You need to have Chrome WebDriver installed

# Open the webpage
driver.get("https://atlas.qa.century-crm.com/")

# Wait for the page to load
wait = WebDriverWait(driver, 20)

# Enter username and password
username = wait.until(EC.presence_of_element_located((By.ID, "username")))
username.send_keys("bwatson@centuryss.com")

password = wait.until(EC.presence_of_element_located((By.ID, "password")))
password.send_keys("Century1")

# Click on the login button
login_button = wait.until(EC.element_to_be_clickable((By.XPATH, "//a[contains(text(),'Log in')]")))
login_button.click()

# Wait for the dashboard to load
# dashboard = wait.until(EC.presence_of_element_located((By.ID, "dashboard")))

# Find and click on the Administration link
administration_link = wait.until(EC.element_to_be_clickable((By.XPATH, "//span[contains(text(),'Administration')]")))
driver.execute_script("arguments[0].click();", administration_link)

# Wait for the Reporting link to be clickable
reporting_link = wait.until(EC.element_to_be_clickable((By.XPATH, "//span[contains(@ng-bind, 'subNavHeader') and contains(text(),'Reporting')]")))

# Click on the Reporting link
driver.execute_script("arguments[0].click();", reporting_link)

# Find and click on the Bulk List Generator link
bulk_list_generator_link = wait.until(EC.element_to_be_clickable((By.XPATH, "//span[contains(@ng-bind, 'nav1.heading') and contains(text(),'Bulk List Generator')]")))
driver.execute_script("arguments[0].click();", bulk_list_generator_link)

# Wait for the dropdown to be clickable
dropdown = wait.until(EC.element_to_be_clickable((By.ID, "bulklist")))

# Click on the dropdown to open it
dropdown.click()

# Introduce a small delay to ensure the dropdown menu is fully loaded
time.sleep(1)  # Adjust the delay time as needed

# List of values to select from the dropdown
values_to_select = [
    "Additional Funds", 
    "Additional Funds w/offer", 
    "Auth Before Letter", 
    "Auth + Client CBP", 
    "Coached Settlement", 
    "Conf/W Creditor", 
    "Hardship", 
    "Loan Coached Settlement", 
    "Loan Estimate", 
    "LOA Needed", 
    "Pending Settlement Auth", 
    "Priority Review", 
    "Stipulation", 
    "Request to Add", 
    "Need to complete a WC", 
    "Global Coupon Reminder", 
    "CFT Coupon Reminder", 
    "Failed Validation", 
    "Failed Verification", 
    "Return", 
    "Term Return", 
    "Final Return", 
    "Loan Docs Out", 
    "NSF CBP", 
    "Client CBP", 
    "Program Outreach", 
    "Deposit reminder - 1 day", 
    "Deposit reminder - 2 days", 
    "Deposit reminder - 3 days", 
    "R01 CFT I agree Text", 
    "R01 Global I agree Text", 
    "Non R01 I agree Text", 
    "Loan Pre-Qualified"
]

for value in values_to_select:
    # Select a value from the dropdown
    option = wait.until(EC.element_to_be_clickable((By.XPATH, "//select[@id='bulklist']/option[text()='" + value + "']")))
    option.click()

    # Check if the checkboxes are available and not disabled
    checkbox_types = ["Text", "Call", "ASACall", "VerbalOnly"]  # Add other types here if needed
    for checkbox_type in checkbox_types:
        checkbox_id = f"outputType{checkbox_type}"
        try:
            checkbox = driver.find_element(By.XPATH, f"//input[@id='{checkbox_id}']")
            if checkbox.is_enabled():
                checkbox.click()
            # else:
                # print(f"Checkbox for value '{value}' and type '{checkbox_type}' is not available or disabled")
        except:
            print(f"Checkbox for value '{value}' and type '{checkbox_type}' is not available or disabled")

    # Click on the button
    button = wait.until(EC.element_to_be_clickable((By.XPATH, "//button[contains(text(),'Create List')]")))
    button.click()
    print(f"'{value}' Bulk List Done!")
    # Introduce a small delay to allow the action to complete
    time.sleep(10)  # Adjust the delay time as needed

# Close the browser
driver.quit()
