import pyautogui
import time

print("Move your mouse to the taskbar icon you want to automate and wait for the coordinates to display. Press Ctrl+C to stop.")

try:
    while True:
        x, y = pyautogui.position()
        print(f"Mouse Position: ({x}, {y})", end='\r')
        time.sleep(0.1)  # Adjust the sleep time as necessary
except KeyboardInterrupt:
    print("\nStopped.") 