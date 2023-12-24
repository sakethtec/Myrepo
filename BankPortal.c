#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 200 // Define the maximum number of accounts
#define HIGHER_AUTHORITY_PIN 1234  //Higer authority pin to see all accounts 
// Structure to represent an account
struct BankAccount {
    char name[50];
    char adharNumber[15];
    double balance;
    int pin;
    int accountNumber;
    int pinAttempts;
};
void displayMenu();//For displaying all Options
void createAccount(struct BankAccount accounts[], int* totalAccounts);//Creating a bank account with name,adharnumber,balence,pin accountnumber
void deleteAccount(struct BankAccount accounts[], int* totalAccounts);//Deleating an account from the given our bank
void showBalance(struct BankAccount accounts[], int accountNumber);//For users to check Balence
void deposit(struct BankAccount accounts[], int accountNumber);//For users to deposite money
void withdraw(struct BankAccount accounts[], int accountNumber);//For users to withdraw money
void showAccountDetails(struct BankAccount accounts[], int totalAccounts);//For users to see account Details
void editAccountDetails(struct BankAccount accounts[], int totalAccounts);//For users to edit account Details
void viewAllAccounts(struct BankAccount accounts[], int totalAccounts);//For Higher authorities to check all accounts

int main() {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int totalAccounts = 0;

    int choice;
    int accountNumber;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &totalAccounts);
                break;
            case 2:
                deleteAccount(accounts, &totalAccounts);
                break;
            case 3:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                showBalance(accounts, accountNumber);
                break;
            case 4:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                deposit(accounts, accountNumber);
                break;
            case 5:
                printf("Enter your account number: ");
                scanf("%d", &accountNumber);
                withdraw(accounts, accountNumber);
                break;
            case 6:
                viewAllAccounts(accounts, totalAccounts);
                break;
            case 7:
                showAccountDetails(accounts, totalAccounts);
                break;
            case 8:
                editAccountDetails(accounts, totalAccounts);
                break;
            case 9:
                printf("Exiting the bank portal. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        getchar();
        getchar();
        system("cls"); 

    } while (choice != 7);

    return 0;
}
//For displaying all Options
void displayMenu() {
    printf("\nBank Portal Menu:\n");
    printf("-----------------------\n");
    printf("1. Create Account\n");
    printf("2. Delete Account\n");
    printf("3. Show Balance\n");
    printf("4. Deposit Money\n");
    printf("5. Withdraw Money\n");
    printf("6. View All Accounts (Higher Authority)\n");
    printf("7. View Your  Account Details (User)\n");
    printf("8. Edit Your  Account Details (User)\n");
    printf("9. Exit\n");
}
//Creating a bank account with name,adharnumber,balence,pin accountnumber
void createAccount(struct BankAccount accounts[], int* totalAccounts) {
    if (*totalAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }
    printf("Enter your name: ");
    scanf("%s", accounts[*totalAccounts].name);
    printf("Enter your Adhar number: ");
    scanf("%s", accounts[*totalAccounts].adharNumber);
    printf("Enter initial balance: ");
    scanf("%lf", &accounts[*totalAccounts].balance);
    printf("Set your 4-digit PIN: ");
    scanf("%d", &accounts[*totalAccounts].pin);
    // Assigning account number (1 to 200)
    accounts[*totalAccounts].accountNumber = *totalAccounts + 1;
    // Increment the total number of accounts
    (*totalAccounts)++;

    printf("Account created successfully! Your account number is: %d\n", accounts[*totalAccounts - 1].accountNumber);
}
//Deleating an account from the given our bank
void deleteAccount(struct BankAccount accounts[], int* totalAccounts) {
    int accountNumber;
    int pin;
    int i;
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    for (i = 0; i < *totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter your PIN to proceed with the account deletion: ");
            scanf("%d", &pin);
            if (pin == accounts[i].pin) {
                // Move all accounts after this one to fill the gap
                for (int j = i; j < *totalAccounts - 1; j++) {
                    accounts[j] = accounts[j + 1];
                }
                // Decrement the total number of accounts
                (*totalAccounts)--;
                printf("Account deleted successfully.\n");
                return;
            } else {
                printf("Incorrect PIN. Account deletion failed.\n");
                return;
            }
        }
    }
    printf("Account not found. Deletion failed.\n");
}
//For users to check Balence
void showBalance(struct BankAccount accounts[], int accountNumber) {
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Your account balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found. Showing balance failed.\n");
}
//For users to deposit money
void deposit(struct BankAccount accounts[], int accountNumber) {
    double amount;
    int pin;
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter the amount to deposit: ");
            scanf("%lf", &amount);
            printf("Enter your PIN to proceed: ");
            scanf("%d", &pin);
            if (pin == accounts[i].pin) {
                accounts[i].balance += amount;
                printf("Deposit successful. Your new balance: %.2lf\n", accounts[i].balance);
                return;
            } else {
                printf("Incorrect PIN. Deposit failed.\n");
                return;
            }
        }
    }
    printf("Account not found. Deposit failed.\n");
}
//For users to withdraw money
void withdraw(struct BankAccount accounts[], int accountNumber) {
    double amount;
    int pin;
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter the amount to withdraw: ");
            scanf("%lf", &amount);
            printf("Enter your PIN to proceed: ");
            scanf("%d", &pin);
            if (pin == accounts[i].pin) {
                if (amount > accounts[i].balance) {
                    printf("Insufficient balance. Withdrawal failed.\n");
                    return;
                }
                accounts[i].balance -= amount;
                printf("Withdrawal successful. Your new balance: %.2lf\n", accounts[i].balance);
                return;
            } else {
                printf("Incorrect PIN. Withdrawal failed.\n");
                return;
            }
        }
    }
    printf("Account not found. Withdrawal failed.\n");
}
//For users to check bank Details
void showAccountDetails(struct BankAccount accounts[], int totalAccounts) {
    int enteredAccountNumber;
    int enteredPin;
    printf("Enter your account number: ");
    scanf("%d", &enteredAccountNumber);
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == enteredAccountNumber) {
            printf("Enter your PIN: ");
            scanf("%d", &enteredPin);
            if (enteredPin == accounts[i].pin) {
                // Reset pinAttempts on successful PIN entry
                accounts[i].pinAttempts = 0;
                // Display account details
                printf("\nAccount Details:\n");
                printf("Name: %s\n", accounts[i].name);
                printf("Adhar Number: %s\n", accounts[i].adharNumber);
                printf("Balance: %.2lf\n", accounts[i].balance);
                printf("-----------------------\n");
                return;
            } else {
                // Increment pinAttempts on unsuccessful PIN entry
                accounts[i].pinAttempts++;
                if (accounts[i].pinAttempts >= MAX_PIN_ATTEMPTS) {
                    printf("Too many incorrect PIN attempts. Transaction cancelled.\n");
                    return;
                }
                printf("Incorrect PIN. Access denied. Attempts remaining: %d\n", MAX_PIN_ATTEMPTS - accounts[i].pinAttempts);
                return;
            }
        }
    }
    printf("Account not found. Access denied.\n");
}
//For users to Edit Account Details
void editAccountDetails(struct BankAccount accounts[], int totalAccounts) {
    int enteredAccountNumber;
    int enteredPin;
    int editChoice;
    printf("Enter your account number: ");
    scanf("%d", &enteredAccountNumber);
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == enteredAccountNumber) {
            printf("Enter your PIN: ");
            scanf("%d", &enteredPin);
            if (enteredPin == accounts[i].pin) {
                // Reset pinAttempts on successful PIN entry
                accounts[i].pinAttempts = 0;
                // Display menu for editing account details
                printf("\nEdit Account Details Menu:\n");
                printf("1. Edit Name\n");
                printf("2. Edit Aadhar Number\n");
                printf("3. Edit PIN\n");
                printf("Enter your choice: ");
                scanf("%d", &editChoice);
                switch (editChoice) {
                    case 1:
                        printf("Enter new name: ");
                        scanf("%s", accounts[i].name);
                        printf("Name updated successfully!\n");
                        break;
                    case 2:
                        printf("Enter new Aadhar number: ");
                        scanf("%s", accounts[i].adharNumber);
                        printf("Aadhar number updated successfully!\n");
                        break;
                    case 3:
                        printf("Enter new PIN: ");
                        scanf("%d", &accounts[i].pin);
                        printf("PIN updated successfully!\n");
                        break;
                    default:
                        printf("Invalid choice. No changes made.\n");
                        break;
                }
                return;
            } else {
                // Increment pinAttempts on unsuccessful PIN entry
                accounts[i].pinAttempts++;

                if (accounts[i].pinAttempts >= MAX_PIN_ATTEMPTS) {
                    printf("Too many incorrect PIN attempts. Transaction cancelled.\n");
                    return;
                }
                printf("Incorrect PIN. Access denied. Attempts remaining: %d\n", MAX_PIN_ATTEMPTS - accounts[i].pinAttempts);
                return;
            }
        }
    }
    printf("Account not found. Access denied.\n");
}
//For Higher authorities to check all accounts
void viewAllAccounts(struct BankAccount accounts[], int totalAccounts) {
    int higherAuthorityPin;
    // Assume a hardcoded higher authority PIN (for demonstration purposes)
    printf("Enter higher authority PIN: ");
    scanf("%d", &higherAuthorityPin);
    if (higherAuthorityPin != HIGHER_AUTHORITY_PIN) {
        printf("Incorrect higher authority PIN. Access denied.\n");
        return;
    }
    printf("\nAll Accounts Details:\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Adhar Number: %s\n", accounts[i].adharNumber);
        printf("Balance: %.2lf\n", accounts[i].balance);
        printf("-----------------------\n");
    }
}
