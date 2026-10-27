
#include <iostream>
using namespace std;

// 1. try, throw and catch
double divide(int numerator, int denominator) {
    if (denominator == 0)
        throw "Division by zero";
    return static_cast<double>(numerator) / denominator;
}

void displayDivision(int numerator, int denominator) {
    try {
        double quotient = divide(numerator, denominator);
        cout << numerator << " / " << denominator
             << " = " << quotient << endl;
    }
    catch (const char *errorMsg) {
        cout << numerator << " / " << denominator
             << " -> Error: " << errorMsg << endl;
    }
}

// 2. Multiple catch blocks and catch-all
void generateException(int option) {
    if (option == 1) throw 10;
    if (option == 2) throw "Text exception";
    if (option == 3) throw 3.5;
    cout << "Choice " << option
         << ": no exception thrown" << endl;
}

void handleException(int option) {
    try {
        generateException(option);
    }
    catch (int number) {
        cout << "Choice " << option
             << ": int caught = " << number << endl;
    }
    catch (const char *textMsg) {
        cout << "Choice " << option
             << ": string caught = " << textMsg << endl;
    }
    catch (...) {
        cout << "Choice " << option
             << ": unknown exception caught" << endl;
    }
}

// 3. User-defined exception classes
class MyError {
public:
    virtual const char *what() const {
        return "Error";
    }

    virtual ~MyError() {}
};

class InsufficientBalance : public MyError {
public:
    const char *what() const override {
        return "Insufficient balance";
    }
};

class InvalidAmount : public MyError {
public:
    const char *what() const override {
        return "Amount must be positive";
    }
};

class IndexOutOfRange : public MyError {
public:
    const char *what() const override {
        return "Index out of range";
    }
};

class Account {
    int currentBalance;

public:
    Account(int initialBalance) {
        currentBalance = initialBalance;
    }

    void withdraw(int withdrawalAmount) {
        if (withdrawalAmount <= 0)
            throw InvalidAmount();

        if (withdrawalAmount > currentBalance)
            throw InsufficientBalance();

        currentBalance = currentBalance - withdrawalAmount;

        cout << "Withdrawn " << withdrawalAmount
             << ", balance = " << currentBalance << endl;
    }
};

void processWithdrawal(Account &bankAccount, int amount) {
    try {
        bankAccount.withdraw(amount);
    }
    catch (const InsufficientBalance &error) {
        cout << "Withdraw " << amount
             << " -> " << error.what() << endl;
    }
    catch (const MyError &error) {
        cout << "Withdraw " << amount
             << " -> " << error.what() << endl;
    }
}

// 4. Array bounds checking
int getElement(const int numbers[], int arraySize, int position) {
    if (position < 0 || position >= arraySize)
        throw IndexOutOfRange();

    return numbers[position];
}

void displayElement(const int numbers[], int arraySize, int position) {
    try {
        int elementValue = getElement(numbers, arraySize, position);

        cout << "Element at index " << position
             << ": " << elementValue << endl;
    }
    catch (const IndexOutOfRange &) {
        cout << "Index " << position
             << " is out of range" << endl;
    }
}

// 5. Rethrowing an exception
void innerFunction() {
    try {
        throw "Problem in inner()";
    }
    catch (const char *errorMsg) {
        cout << "inner() caught: " << errorMsg
             << " - rethrowing" << endl;
        throw;
    }
}

int main() {
    cout << "--- try, throw and catch ---" << endl;
    displayDivision(10, 2);
    displayDivision(7, 2);
    displayDivision(0, 5);
    displayDivision(-9, 3);
    displayDivision(10, 0);

    cout << "\n--- Multiple catch blocks and catch-all ---" << endl;
    for (int choice = 1; choice <= 4; choice++)
        handleException(choice);

    cout << "\n--- User-defined exceptions ---" << endl;
    Account savingsAccount(1000);
    processWithdrawal(savingsAccount, 500);
    processWithdrawal(savingsAccount, 500);
    processWithdrawal(savingsAccount, 1);
    processWithdrawal(savingsAccount, 0);
    processWithdrawal(savingsAccount, -50);

    cout << "\n--- Array bounds checking ---" << endl;
    int values[3] = {10, 20, 30};
    displayElement(values, 3, 2);
    displayElement(values, 3, 3);
    displayElement(values, 3, -1);

    cout << "\n--- Rethrowing an exception ---" << endl;
    try {
        innerFunction();
    }
    catch (const char *errorMsg) {
        cout << "main() caught: " << errorMsg << endl;
    }

    return 0;
}

