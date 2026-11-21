
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int rollNo;

    // Parameterized constructor
    Student(string n, int r)
    {
        name = n;
        rollNo = r;
    }

    // Copy constructor
    Student(const Student &s)
    {
        name = s.name;
        rollNo = s.rollNo;

        cout << "Copy Constructor Called" << endl;
    }

    // Display function
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }
};

int main()
{
    // Creating first object
    Student s1("Sharyu", 101);

    cout << "Before Copy Operation:" << endl;
    s1.display();

    // Creating second object using copy constructor
    Student s2(s1);

    cout << "\nAfter Copy Operation:" << endl;

    cout << "\nStudent 1 Details:" << endl;
    s1.display();

    cout << "\nStudent 2 Details:" << endl;
    s2.display();

    return 0;
}

