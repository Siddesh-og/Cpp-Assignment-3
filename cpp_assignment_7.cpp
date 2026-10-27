
#include <iostream>
using namespace std;

// 1. Compile-time polymorphism: Function overloading
class Area {
public:
    int area(int side) {
        if (side <= 0) return 0;
        return side * side;
    }

    int area(int length, int breadth) {
        if (length <= 0 || breadth <= 0) return 0;
        return length * breadth;
    }

    double area(double radius) {
        if (radius <= 0) return 0;
        return 3.14 * radius * radius;
    }
};

// 2. Compile-time polymorphism: Operator overloading
class Complex {
    int realPart, imaginaryPart;

public:
    Complex(int realValue = 0, int imaginaryValue = 0) {
        realPart = realValue;
        imaginaryPart = imaginaryValue;
    }

    Complex operator+(const Complex &other) const {
        return Complex(realPart + other.realPart,
                       imaginaryPart + other.imaginaryPart);
    }

    void show() const {
        if (imaginaryPart < 0)
            cout << realPart << " - " << -imaginaryPart << "i" << endl;
        else
            cout << realPart << " + " << imaginaryPart << "i" << endl;
    }
};

// 3. Run-time polymorphism: Virtual function
class Shape {
public:
    virtual void draw() const {
        cout << "Sketching a generic shape" << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Sketching a circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Sketching a rectangle" << endl;
    }
};

int main() {
    Area calc;

    // TC1 – Function overloading (int)
    cout << "--- TC1: Function Overloading (int) ---" << endl;
    cout << "Square (side 7) area: " << calc.area(7) << endl;
    cout << "Rectangle (5 x 8) area: " << calc.area(5, 8) << endl;

    // TC2 – Function overloading (double)
    cout << "\n--- TC2: Function Overloading (double) ---" << endl;
    cout << "Circle (radius 3) area: " << calc.area(3.0) << endl;

    // TC3 – Invalid sizes
    cout << "\n--- TC3: Invalid Sizes ---" << endl;
    cout << "Square with side -2: " << calc.area(-2) << endl;
    cout << "Rectangle with length -5: " << calc.area(-5, 8) << endl;
    cout << "Circle with radius -2.5: " << calc.area(-2.5) << endl;

    // TC4 – Operator overloading
    cout << "\n--- TC4: Operator Overloading ---" << endl;
    Complex p(2, 5), q(4, 1);
    Complex sum1 = p + q;
    cout << "p + q = ";
    sum1.show();

    // TC5 – Operator overloading (negative values)
    cout << "\n--- TC5: Operator Overloading (Negative Values) ---" << endl;
    Complex r(-3, -6);
    Complex sum2 = r + p;

    cout << "r = ";
    r.show();

    cout << "r + p = ";
    sum2.show();

    // TC6 and TC7 – Virtual function
    cout << "\n--- TC6: Virtual Function (Derived Objects) ---" << endl;
    Shape sh;
    Circle ci;
    Rectangle re;
    Shape *sp;

    sp = &ci;
    sp->draw();

    sp = &re;
    sp->draw();

    cout << "\n--- TC7: Virtual Function (Base Object) ---" << endl;
    sp = &sh;
    sp->draw();

    return 0;
}

