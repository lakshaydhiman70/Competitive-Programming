from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import Select
import logging
import time

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

# Launch the browser
driver = webdriver.Chrome()  # Ensure you have the correct WebDriver installed

def login(wait, driver, username, password):
    """
    Log into the website with the provided username and password.
    """
    # Navigate to the login page
    driver.get("https://staging.acme.century-crm.com/")
    
    # Enter username
    logging.info("Entering username")
    username_field = wait.until(EC.presence_of_element_located((By.ID, "username")))
    username_field.send_keys(username)
    
    # Enter password
    logging.info("Entering password")
    password_field = wait.until(EC.presence_of_element_located((By.ID, "password")))
    password_field.send_keys(password)
    
    # Click on the login button
    logging.info("Clicking login button")
    login_button = wait.until(EC.element_to_be_clickable((By.XPATH, "//a[contains(text(),'Log in')]")))
    login_button.click()

def search_clients(driver, wait, client_ids):
    logging.info("Clicking Client Manager link")
    client_manager_link = wait.until(EC.element_to_be_clickable((By.XPATH, "//span[contains(text(),'Client Manager')]")))
    driver.execute_script("arguments[0].click();", client_manager_link)
    
    # Wait for the recent client link to be present and visible
    logging.info("Waiting for Recent Clients link to be visible")
    search_client_link = wait.until(EC.visibility_of_element_located((By.XPATH, "//span[@ng-bind='nav.heading' and text()='Search Clients']")))
    driver.execute_script("arguments[0].click();", search_client_link)

    for client_id in client_ids:
        contract_id_input = wait.until(EC.presence_of_element_located((By.XPATH, "//input[@ng-model='search.contractId']")))
        contract_id_input.clear()  # Clear the input field
        contract_id_input.send_keys(client_id)
    
        # Find and click on the search button
        search_button = wait.until(EC.element_to_be_clickable((By.XPATH, "//input[@value='Search']")))
        search_button.click()
        time.sleep(3)
        click_client_id_link(driver, wait)

        

def click_client_id_link(driver, wait):
    # Find all rows containing search results
    wait.until(EC.presence_of_all_elements_located((By.XPATH, "//tr[@ng-repeat='result in data.data']")))
    rows = wait.until(EC.presence_of_all_elements_located((By.XPATH, "//tr[@ng-repeat='result in data.data']")))
    for row in rows:
        try:
            # Find the client ID link within the row
            client_id_link = row.find_element(By.XPATH, ".//a[@ng-click='redirectTo(result.reference)']")
            client_id = client_id_link.get_attribute("innerText")
            client_id_link.click()
            logging.info(f"Clicked on client ID link for {client_id}")
        except Exception as e:
            logging.error(f"Failed to click on client ID link in the row: {e}")

def click_creditors_tab(driver, wait):
    try:
        # Find and click on the "Creditors" tab
        wait.until(EC.element_to_be_clickable((By.XPATH, "//a[@ng-click='redirectPage(t.route)' and text()='Creditors']")))
        creditors_tab = wait.until(EC.element_to_be_clickable((By.XPATH, "//a[@ng-click='redirectPage(t.route)' and text()='Creditors']")))
        creditors_tab.click()
        logging.info("Clicked on Creditors tab")
    except Exception as e:
        logging.error(f"Failed to click on Creditors tab: {e}")


def add_loan(driver, wait):
    try:
        # Wait for the overlay to disappear
        wait.until(EC.invisibility_of_element_located((By.CSS_SELECTOR, "div.page-splash")))
        
        # Find and click the "Add Account" button
        add_account_button = wait.until(EC.element_to_be_clickable((By.XPATH, "//input[@value='Add Account' and @ng-click='vmSettlementList.view.toggleModify();']")))
        add_account_button.click()
        logging.info("Clicked on Add Account button")



        # Wait for the link to be clickable
        add_link = wait.until(EC.element_to_be_clickable((By.XPATH, "//a[@class='action-anchor' and @ng-click='vmLoanDetail.view.modifyPopUpClick(res)' and text()='Add']")))
        add_link.click()

        #creditor id
        wait.until(EC.presence_of_element_located((By.XPATH, "//input[@ng-model='filter.Id']")))
        creditor_id_input = wait.until(EC.presence_of_element_located((By.XPATH, "//input[@ng-model='filter.Id']")))
        creditor_id_input.clear()  # Clear the input field
        creditor_id_input.send_keys(7)

        search_button = wait.until(EC.element_to_be_clickable((By.XPATH, "//input[@class='btn btn-primary btn-sm btn-search-modal' and @value='search' and @ng-click='search()']")))
        search_button.click()

        select_link = wait.until(EC.element_to_be_clickable((By.XPATH, "(//a[@ng-click='selectLender(lenDetail.Id,lenDetail.Name,lenDetail.DebtType)'])[1]")))
        select_link.click()

        #account number
        acc_number_id_input = wait.until(EC.presence_of_element_located((By.XPATH, "//input[@ng-model='res.account_number']")))
        acc_number_id_input.clear()  # Clear the input field
        acc_number_id_input.send_keys(1234567890)

        #balance
        balance_input = wait.until(EC.presence_of_element_located((By.ID, "balance")))
        balance_input.clear()  # Clear any pre-existing value
        balance_input.send_keys(100.23)

        #fee %
        fee_input = wait.until(EC.presence_of_element_located((By.ID, "feeAmount")))
        fee_input.clear()  # Clear the input field
        fee_input.send_keys(12)

        # Wait for the status dropdown to be present
        status_dropdown = wait.until(EC.presence_of_element_located((By.NAME, "status")))
        select = Select(status_dropdown)
        select.select_by_visible_text("Active")

        #click on the save button
        save_button = wait.until(EC.element_to_be_clickable((By.XPATH, "//input[@type='button' and @value='Save' and @ng-click='vmLoanDetail.view.save(loanForm)']")))
        save_button.click()
        
        time.sleep(10)


    except Exception as e:
        logging.error(f"Failed to click on Add Account button: {e}")


try:
    logging.info("Opening the webpage")
    driver.get("https://staging.acme.century-crm.com/")
    
    # Wait for the page to load
    wait = WebDriverWait(driver, 20000000000000000000)
    
    #calling login
    login(wait, driver, "vipinmittal@finxera.com", "12345678")

    client_ids = ["35504037"]  # Add other types here if needed

    search_clients(driver, wait, client_ids)

    time.sleep(3) 

    click_creditors_tab(driver, wait)

    time.sleep(7)

    add_loan(driver, wait)

    time.sleep(5)

except Exception as e:
    logging.error(f"An error occurred: {e}")

finally:
    logging.info("Closing the browser")
    driver.quit()



