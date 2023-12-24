# Myrepo

## Projects

1. [Simple Banking Portal](#simple-banking-portal)
2. [MY Hotel Management System](#my-hotel-management-system)
3. [Sliding Puzzle Game](#sliding-puzzle-game)
4. [Tic-Tac-Toe Game](#tic-tac-toe-game)

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
```
---
## MY Hotel Management System

Welcome to the MY Hotel Management System! This simple console-based application allows you to manage hotel rooms, including the ability to add, view, search, and delete rooms.

### Features

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

### Room Types

1. Single Bedroom
2. Double Bedroom
3. Duplex
4. Suite
5. Apartment

### Usage

1. Run the hotel_management.py file.

    ```bash
    python hotel_management.py
    ```

2. Follow the on-screen prompts to interact with the hotel management system.

### Data Storage

Room data is stored in the hotel_data.txt file. You can modify this file to add or remove rooms manually.

**Note:** Each room type has a limit of 20 rooms.

Feel free to explore and enhance the functionality of this hotel management system based on your requirements.

Happy managing!
---
## Sliding Puzzle Game

Welcome to the Sliding Puzzle Game! This console-based application allows you to play a classic sliding puzzle game on a 3x3 board.

### Instructions

**Goal:**
The goal of the game is to arrange the numbers on the board in ascending order from left to right and top to bottom. The empty space is represented by a blank position.

**How to Play:**
Use the following keys to make moves:

- Press 'w' to move up.
- Press 's' to move down.
- Press 'a' to move left.
- Press 'd' to move right.

Continue making moves until you arrange the numbers in the correct order. You win the game when all numbers are in ascending order, and the empty space is in the bottom right corner.

### Constraints

- You have a maximum of 100 moves to complete the game.

### Compiling and Running

Compile the code using a C compiler (e.g., gcc):

```bash
gcc sliding_puzzle.c -o sliding_puzzle
```
### Usage

Run the compiled executable to start the Sliding Puzzel:

```bash
./sliding_puzzle
```
---
# Tic-Tac-Toe Game

Welcome to the Tic-Tac-Toe Game! This console-based application allows two players to play the classic Tic-Tac-Toe game on a 3x3 grid.

## Game Rules

1. Players take turns to enter their choices, either "O" or "X", in an empty cell of the 3x3 grid.
2. The game checks after each move for a win or a draw.
3. A player wins if they have three of their symbols ("O" or "X") in a row, column, or diagonal.
4. The game ends in a draw if there are no empty cells left and no player has won.

## How to Play

1. Run the Python script using `python tic_tac_toe.py`.
2. Enter your choice at each turn by inputting the corresponding cell number (1 to 9).
3. The game will display the updated board after each move.
4. The game will announce the winner or declare a draw at the end.

## Example Board
_ | _ | _ 
_ | _ | _ 
  |   | 

## Game Completion

The game continues until a player wins, or the board is filled, resulting in a draw.

## Running the Game

Ensure you have Python installed on your system. Run the script using the command:

```bash
python tic_tac_toe.py
```
