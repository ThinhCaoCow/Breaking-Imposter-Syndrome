// Financial Account System
// Create an Account class with fields: accountNumber, accountHolder, balance.
// Started 14/8/2025 -- Temp Ended 19/8/2025
// Implement methods: deposit(), withdraw(), displayBalance().
// Use a std::vector<Account> to manage multiple accounts.
// Develop a CLI menu that allows users to choose operations.
// Add input validation to handle overdraw attempts.
//Use fstream to save and load account data from a file.
//Include documentation for each method in your code and a class diagram in your repo.
//Record a demo using a screen recorder and include screenshots in the README.md.
// NEW PLAN, Develop the foundations for all the programs then complete them one by one. Procrastination and the lack of knowledge is killing this project.
#include <iostream>
#include <string>

class Account { // Develops a "class" which is a variable that holds multiple variables just like the struct in C
private:
    int accountNumber;
    std::string accountHolder;
    double balance;
public: // Empty Functions
    Account(int accNum, const std::string& holder, double initialBalance);

    void deposit(double amount);

    bool withdraw(double amount);

    void displayBalance() const;

    int getAccountNumber() const;
    std::string getAccountHolder() const;
    double getBalance() const;
};