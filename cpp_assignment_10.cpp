
#include <iostream>
using namespace std;

// Function template: Find maximum
template <class T>
T findMax(T num1, T num2) {
    return (num1 > num2) ? num1 : num2;
}

// Function template: Swap values
template <class T>
void exchangeValues(T &first, T &second) {
    T temporary = first;
    first = second;
    second = temporary;
}

// Class template: Calculator
template <class T>
class Calculator {
private:
    T num1, num2;

public:
    Calculator(T x, T y) {
        num1 = x;
        num2 = y;
    }

    T add() {
        return num1 + num2;
    }

    T subtract() {
        return num1 - num2;
    }

    T multiply() {
        return num1 * num2;
    }

    bool divide(T &answer);
};

// Defining member function outside the class
template <class T>
bool Calculator<T>::divide(T &answer) {
    if (num2 == 0)
        return false;

    answer = num1 / num2;
    return true;
}

// Function template using class template
template <class T>
void displayResults(Calculator<T> calc) {
    T quotient = T();

    cout << "Sum = " << calc.add()
         << ", Difference = " << calc.subtract()
         << ", Product = " << calc.multiply();

    if (calc.divide(quotient))
        cout << ", Quotient = " << quotient << endl;
    else
        cout << ", Quotient = not possible (division by zero)" << endl;
}

int main() {

    cout << "--- Function template: findMax ---" << endl;

    cout << "Maximum of 10 and 20: " << findMax(10, 20) << endl;
    cout << "Maximum of 7 and 7: " << findMax(7, 7) << endl;
    cout << "Maximum of -5 and -9: " << findMax(-5, -9) << endl;
    cout << "Maximum of 3.5 and 2.5: " << findMax(3.5, 2.5) << endl;
    cout << "Maximum of 'a' and 'z': " << findMax('a', 'z') << endl;

    cout << "\n--- Function template: exchangeValues ---" << endl;

    int value1 = 5, value2 = 8;

    cout << "Before swap: value1 = " << value1
         << ", value2 = " << value2 << endl;

    exchangeValues(value1, value2);

    cout << "After swap: value1 = " << value1
         << ", value2 = " << value2 << endl;

    double decimal1 = 1.5, decimal2 = 2.5;

    cout << "Before swap: decimal1 = " << decimal1
         << ", decimal2 = " << decimal2 << endl;

    exchangeValues(decimal1, decimal2);

    cout << "After swap: decimal1 = " << decimal1
         << ", decimal2 = " << decimal2 << endl;

    cout << "\n--- Class template: Calculator ---" << endl;

    Calculator<int> calc1(20, 5);
    cout << "int (20, 5) -> ";
    displayResults(calc1);

    Calculator<double> calc2(7.5, 2.5);
    cout << "double (7.5, 2.5) -> ";
    displayResults(calc2);

    Calculator<int> calc3(10, 0);
    cout << "int (10, 0) -> ";
    displayResults(calc3);

    Calculator<int> calc4(7, 2);
    cout << "int (7, 2) -> ";
    displayResults(calc4);

    Calculator<int> calc5(-8, 2);
    cout << "int (-8, 2) -> ";
    displayResults(calc5);

    return 0;
}

