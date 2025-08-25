#include <iostream>
using namespace std;

// assuming exam class holds a dynamic array of all students apeared in an exam
// with an array that holds their marks at the same index
// only to show dma
class Exam
{
private:
    string examName;
    int date; // using int for simplicity
    string *studentNames;
    float *marks;
    int noOfStudents;

public:
    Exam(string examName = "", int date = -1, string *studentsNamesIn = nullptr, float *marksIn = nullptr, int noOfStudents = 0) : examName(examName), date(date), noOfStudents(noOfStudents)
    {
        studentNames = new string[noOfStudents];
        marks = new float[noOfStudents];

        for (int i = 0; i < noOfStudents; i++)
        {
            studentNames[i] = studentsNamesIn[i];
            marks[i] = marksIn[i];
        }
    }

    Exam(const Exam &other)
    {
        this->examName = other.examName;
        this->date = other.date;
        this->noOfStudents = other.noOfStudents;
        // after this only pointers are copied
        studentNames = other.studentNames;
        marks = other.marks;
    }

    void setExamName(const string &name)
    {
        examName = name;
    }

    void setDate(int d)
    {
        date = d;
    }

    void setStudentRecord(int index, const string &student, float mark)
    {
        if (index >= 0 && index < noOfStudents)
        {
            studentNames[index] = student;
            marks[index] = mark;
        }
    }

    void display()
    {
        cout << "Exam: " << examName << " on " << date << endl;
        for (int i = 0; i < noOfStudents; i++)
        {
            cout << studentNames[i] << " : " << marks[i] << endl;
        }
    }
};

int main()
{
    string students[] = {"S1", "S2", "S3"};
    float marks[] = {85.5, 92.0, 76.5};

    Exam exam1("Midterm", 20250825, students, marks, 3);
    exam1.display();

    Exam exam2(exam1);

    cout << "\nAfter shallow copy:\n";
    exam2.display();

    // both exam1 and exam2 now point to the same arrays
}