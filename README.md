# Myrepo

## Projects

1. [Simple Banking Portal](#simple-banking-portal)
2. [MY Hotel Management System](#my-hotel-management-system)

---

## Simple Banking Portal

A console-based banking portal implemented in C.

### Introduction

The Simple Banking Portal is a console-based application designed for basic banking operations. Users can create accounts, perform transactions, and access account details. It includes features such as account creation, deletion, balance checking, deposit, withdrawal, and administrative functions.

### Features

- **Create a new bank account:** Users can create a new bank account by providing their name, Aadhar number, initial balance, and a 4-digit PIN.
- **Delete an existing bank account:** Account holders can delete their accounts after confirming their PIN.
- **Check account balance:** Users can check their account balance by entering their account number and PIN.
- **Deposit money into an account:** Account holders can deposit money into their accounts by specifying the amount.
- **Withdraw money from an account:** Users can withdraw money from their accounts, provided they have sufficient balance and enter the correct PIN.
- **View all accounts (Higher Authority):** Higher authorities can view details of all accounts by entering a special PIN.
- **View account details (User):** Account holders can view their account details, including name, Aadhar number, and balance.
- **Edit account details (User):** Users can edit certain details of their accounts, including name, Aadhar number, and PIN.

### Prerequisites

Ensure you have a C compiler installed on your system.

### Installation

1. **Clone the repository:**

    ```bash
    git clone https://github.com/your-username/simple-banking-portal.git
    cd simple-banking-portal
    ```

2. **Compile the C code:**

    ```bash
    gcc main.c -o banking_portal
    ```

### Usage

Run the compiled executable to start the banking portal:

```bash
./banking_portal
# MY Hotel Management System

Welcome to the MY Hotel Management System! This simple console-based application allows you to manage hotel rooms, including the ability to add, view, search, and delete rooms.

## Features

1. **Add Room:**
   - Add a new room to the hotel by providing the room number and selecting the room type.

2. **View Rooms:**
   - View all available rooms categorized by room type.

3. **Search Room:**
   - Search for a specific room using its room number.

4. **Delete Room:**
   - Delete a room based on its room number.

5. **Save and Exit:**
   - Save the current state of rooms to a file and exit the system.

## Room Types

- Single Bedroom
- Double Bedroom
- Duplex
- Suite
- Apartment

## Usage

1. Run the `hotel_management.py` file.
2. Follow the on-screen prompts to interact with the hotel management system.

## Data Storage

Room data is stored in the `hotel_data.txt` file. You can modify this file to add or remove rooms manually.

**Note:** Each room type has a limit of 20 rooms.

Feel free to explore and enhance the functionality of this hotel management system based on your requirements.

Happy managing!
