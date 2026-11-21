
#include <iostream>
#include <cstdint>
using namespace std;

class Person
{
public:
    virtual ~Person() {}
};

class Student : public Person
{
public:
    void display()
    {
        cout << "Student object identified successfully.\n";
    }
};

int main()
{
    double marks;

    cout << "Enter student's marks: ";
    cin >> marks;

    // static_cast
    int integerMarks = static_cast<int>(marks);

    cout << "\n--- static_cast ---\n";
    cout << "Original marks: " << marks << endl;
    cout << "Integer marks: " << integerMarks << endl;

    // dynamic_cast
    Student student;
    Person* personPtr = &student;

    Student* studentPtr =
        dynamic_cast<Student*>(personPtr);

    cout << "\n--- dynamic_cast ---\n";

    if (studentPtr != nullptr)
    {
        studentPtr->display();
    }
    else
    {
        cout << "Conversion failed.\n";
    }

    // const_cast
    int value = 10;
    const int& constRef = value;

    int& modifiableRef = const_cast<int&>(constRef);
    modifiableRef = 20;

    cout << "\n--- const_cast ---\n";
    cout << "Modified value: " << value << endl;

    // reinterpret_cast
    uintptr_t address =
        reinterpret_cast<uintptr_t>(&value);

    cout << "\n--- reinterpret_cast ---\n";
    cout << "Integer representation of address: "
         << address << endl;

    return 0;
}

