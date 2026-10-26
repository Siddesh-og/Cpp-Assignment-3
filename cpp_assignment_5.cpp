#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int studentRoll;
    string studentName;
    int studentMarks;
    static int totalCount;

public:
    Student(int studentRoll, string studentName, int studentMarks) {
        this->studentRoll = studentRoll;
        this->studentName = studentName;
        this->studentMarks = studentMarks;
        totalCount++;
    }

    Student& setName(string newName) {
        this->studentName = newName;
        return *this;
    }

    Student& setMarks(int newMarks) {
        this->studentMarks = newMarks;
        return *this;
    }

    inline bool isPass() {
        return studentMarks >= 40;
    }

    inline void display();

    static int getCount() {
        return totalCount;
    }

    friend class Teacher;
};

int Student::totalCount = 0;

inline void Student::display() {
    cout << "Roll No: " << studentRoll
         << ", Name: " << studentName
         << ", Marks: " << studentMarks
         << ", Result: " << (isPass() ? "Pass" : "Fail") << endl;
}

class Teacher {
public:
    void addGraceMarks(Student &student, int extraMarks) {
        student.studentMarks = student.studentMarks + extraMarks;
    }
};

int main() {
    Student student1(101, "SIDDESH", 99);
    Student student2(102, "Mayank", 80);

    cout << "Total students: " << Student::getCount() << endl;

    cout << "\n--- Initial details ---" << endl;
    student1.display();
    student2.display();

    cout << "\n--- Function chaining using this pointer ---" << endl;
    student2.setName("Rahul Patil").setMarks(80);
    student2.display();

    cout << "\n--- Friend class adds 10 grace marks to s1 ---" << endl;
    Teacher teacherObj;
    teacherObj.addGraceMarks(student1, 10);
    student1.display();

    return 0;
}
