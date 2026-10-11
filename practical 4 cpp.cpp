#include <iostream>
using namespace std;
 
//References and Pointers
 
void swapByReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
 
void swapByPointer(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
class Student
{
    int rollNo;
    float marks;
 
public:
    Student(int r, float m)
    {
        rollNo = r;
        marks = m;
    }
    void display()
    {
        cout << "Roll No: " << rollNo << ", Marks: " << marks << endl;
    }
};
 
int main()
{
    //REFERENCES AND POINTERS 
    cout << "= PART A: REFERENCES AND POINTERS =" << endl;
 
    int a = 10, b = 20;
    int &ref = a;      // reference: another name for a
    int *ptr = &b;     // pointer: stores the address of b
 
    cout << "a = " << a << ", ref = " << ref << endl;
    cout << "Address of a   : " << &a << endl;
    cout << "Address of ref : " << &ref << endl;
    cout << "b = " << b << ", *ptr = " << *ptr << endl;
    cout << "ptr holds address: " << ptr << endl;
 
    ref = 50;          
    *ptr = 60;         
    cout << "\nAfter ref = 50 and *ptr = 60:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
 
    int x, y;
    cout << "\nEnter two numbers: ";
    cin >> x >> y;
 
    int x2 = x, y2 = y;
 
    swapByReference(x, y);
    cout << "Swap by reference: x = "<< x<< ", y = " <<y << endl;
 
    swapByPointer(&x2, &y2);
    cout << "Swap by pointer  : x = "<<x2 << ", y = " <<y2 << endl;
 
    //NEW AND DELETE OPERATORS
    cout << "\n= NEW AND DELETE OPERATORS =" << endl;
 
    // Single variable
    int *p = new int(25);
    cout << "Dynamic integer value: " << *p << endl;
    delete p;
 
    // Dynamic array
    int n;
    cout << "\nEnter number of subjects: ";
    cin >> n;
 
    float *marks = new float[n];
    float total =0;
 
    for (int i = 0; i< n;i++)
    {
        cout << "Enter marks of subject " << i + 1 << ": ";
        cin >> marks[i];
        total = total + marks[i];
    }
 
    cout << "Total   = " <<total << endl;
    cout << "Average = "<< total / n << endl;
    delete[] marks;
 
    // Dynamic object
    Student *sp = new Student(1, 85.5);
    cout << "\nDynamic object -> ";
    sp->display();
    delete sp;
 
    cout << "\nMemory freed using delete." << endl;
    return 0;
}
