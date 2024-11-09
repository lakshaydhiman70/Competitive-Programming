import pyautogui
import time

# Coordinates of the taskbar icon (replace with your coordinates)
taskbar_icon_coords = (1552, 1046)  # Replace (x, y) with actual coordinates

# VPN password
vpn_password = "Morale-Fondue-Life7"

# Click on the taskbar icon to open the VPN client
pyautogui.click(taskbar_icon_coords[0], taskbar_icon_coords[1])
print("Clicked on the taskbar icon.")

# Give the VPN client time to open (adjust if necessary)
time.sleep(4)  # Increase this if needed
print("Waited for the VPN client to open.")

# Press Enter to ensure the window is active and potentially open the login dialog
pyautogui.press('enter')

print("Pressed Enter to ensure the window is active.")
time.sleep(3)

# Click at the location of the password field to ensure it's focused

# Adjust the coordinates to match the password field location if necessary
# These coordinates should be where the password field is on your screen
password_field_coords = (1705, 855)  # Example coordinates, replace with actual ones
pyautogui.click(password_field_coords[0], password_field_coords[1])
print("Clicked on the password field to focus it.")
time.sleep(3)

# Type the VPN password
pyautogui.typewrite(vpn_password, interval=0.1)
print("Typed the VPN password.")
# time.sleep(2)

# Press Enter to click the Connect button (adjust if necessary)
pyautogui.press('enter')
print("Pressed Enter to connect.")
