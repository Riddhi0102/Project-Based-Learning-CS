import time
from datetime import datetime as dt
import tkinter as tk
from tkinter import messagebox, simpledialog

# File paths (adjust as per your OS)
hosts_path = "C:\\Windows\\System32\\drivers\\etc\\hosts"  # Windows
redirect = "127.0.0.1"
website_list = []

# Function to block websites
def block_websites(start_hour, end_hour):
    current_time = dt.now()
    if start_hour <= current_time.hour < end_hour:
        with open(hosts_path, 'r+') as file:
            content = file.read()
            for website in website_list:
                if website not in content:
                    file.write(f"{redirect} {website}\n")
        messagebox.showinfo("Blocking Status", "Websites blocked during work hours.")
    else:
        unblock_websites()

# Function to manually unblock websites
def unblock_websites():
    with open(hosts_path, 'r+') as file:
        content = file.readlines()
        file.seek(0)
        for line in content:
            if not any(website in line for website in website_list):
                file.write(line)
        file.truncate()
    messagebox.showinfo("Unblocking Status", "Websites have been unblocked.")

# Function to add a website to the block list
def add_website():
    website = simpledialog.askstring("Add Website", "Enter the website URL (e.g., www.example.com):")
    if website:
        website_list.append(website)
        website_listbox.insert(tk.END, website)
        messagebox.showinfo("Success", f"Website {website} added to the block list.")

# Function to remove a website from the block list
def remove_website():
    selected_website = website_listbox.curselection()
    if selected_website:
        website = website_listbox.get(selected_website)
        website_list.remove(website)
        website_listbox.delete(selected_website)
        messagebox.showinfo("Success", f"Website {website} removed from the block list.")

# Function to start blocking
def start_blocking():
    try:
        start_hour = int(start_hour_entry.get())
        end_hour = int(end_hour_entry.get())
        block_websites(start_hour, end_hour)
    except ValueError:
        messagebox.showerror("Input Error", "Please enter valid start and end hours (numbers only).")

# GUI setup
root = tk.Tk()
root.title("Website Blocker")

# Input for blocking hours
tk.Label(root, text="Start Hour (24-hour format):").pack(pady=5)
start_hour_entry = tk.Entry(root)
start_hour_entry.pack(pady=5)

tk.Label(root, text="End Hour (24-hour format):").pack(pady=5)
end_hour_entry = tk.Entry(root)
end_hour_entry.pack(pady=5)

# Website list
tk.Label(root, text="Websites to Block:").pack(pady=5)
website_listbox = tk.Listbox(root, width=50, height=10)
website_listbox.pack(pady=5)

# Buttons
tk.Button(root, text="Add Website", command=add_website).pack(pady=5)
tk.Button(root, text="Remove Website", command=remove_website).pack(pady=5)
tk.Button(root, text="Start Blocking", command=start_blocking).pack(pady=5)
tk.Button(root, text="Unblock Websites", command=unblock_websites).pack(pady=5)  # New button to manually unblock

# Run the GUI loop
root.mainloop()