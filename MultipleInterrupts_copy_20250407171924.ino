import tkinter as tk
import RPi.GPIO as GPIO

# ---------------------------
# GPIO Setup
# ---------------------------
GPIO.setmode(GPIO.BOARD)

# Define LED physical pins
LED_PINS = {
    "Red": 11,
    "Green": 13,
    "Blue": 15
}

# Set up LED pins as output and turn them off initially
for pin in LED_PINS.values():
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.LOW)

# ---------------------------
# LED Control Functions
# ---------------------------
def turn_on_led():
    """Turn on the selected LED and turn off others."""
    selected_color = color_var.get()
    for color, pin in LED_PINS.items():
        GPIO.output(pin, GPIO.HIGH if color == selected_color else GPIO.LOW)

def exit_program():
    """Cleanup GPIO and close the application."""
    GPIO.cleanup()
    window.destroy()

# ---------------------------
# GUI Setup
# ---------------------------
window = tk.Tk()
window.title("LED Controller")
window.geometry("200x150")  # Optional: sets a fixed size

color_var = tk.StringVar(value="Red")

# Create radio buttons for color selection
for color in LED_PINS:
    tk.Radiobutton(
        window,
        text=color,
        variable=color_var,
        value=color,
        command=turn_on_led
    ).pack(anchor="w", padx=10, pady=2)

# Create an Exit button
tk.Button(
    window,
    text="Exit",
    command=exit_program,
    bg="red",
    fg="white"
).pack(pady=10)

# Start the GUI event loop
window.mainloop()
