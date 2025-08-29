

// assuming each row is a student and the no of columns in each row is their enrolled courses
//
#include <iostream>
using namespace std;

class CourseEnrolled
{
private:
    string name;
    float marks;

public:
    CourseEnrolled(string name = "", float marks = 0) : name(name), marks(marks) {}

    void setName(string name)
    {
        this->name = name;
    }

    void setMarks(float marks)
    {
        this->marks = marks;
    }

    string getName()
    {
        return name;
    }

    float getMarks()
    {
        return marks;
    }
};

class Student
{
private:
    string name;
    CourseEnrolled *courses = nullptr;
    int noOfCourses;
    float averageMarks; // of each student across all courses

public:
    Student(string name = "", int noOfCourses = 0, float avg = 0) : name(name), noOfCourses(noOfCourses), averageMarks(avg)
    {
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void assignCourses(int noOfCourses)
    {
        string tempString;
        float tempFloat = 0, tempSum = 0;
        this->noOfCourses = noOfCourses;

        courses = new CourseEnrolled[noOfCourses];
        for (int i = 0; i < noOfCourses; i++)
        {
            cout << "Enter Name Of Course " << i + 1 << ": ";
            cin >> tempString;
            cout << "Enter Marks Obtained in " << tempString << ": ";
            cin >> tempFloat;
            tempSum += tempFloat;
            courses[i].setName(tempString);
            courses[i].setMarks(tempFloat);
        }
        this->averageMarks = tempSum / noOfCourses;
    }

    void displayCourses()
    {
        // cout << name << "'s courses" << endl;
        for (int i = 0; i < noOfCourses; i++)
        {
            cout << courses[i].getName() << ",";
        }
        // cout << endl;
    }

    void displayAverageMarks()
    {
        cout << "Average Marks: " << averageMarks;
    }

     ~Student() {
        delete[] courses;
        courses = nullptr;
    }

};

int main()
{
    Student *students; // for rows
    // columns are stored in "Student" objects themselves

    int noOfStudents;
    string tempString;
    int tempInt;

    cout << "Enter No Of Students : ";
    cin >> noOfStudents;
    students = new Student[noOfStudents];
    for (int i = 0; i < noOfStudents; i++)
    {
        cout << "Enter Student " << i + 1 << "'s name: ";
        cin >> tempString;
        students[i].setName(tempString);
        cout << "Enter " << tempString << " no of enrolled courses: ";
        cin >> tempInt;
        students[i].assignCourses(tempInt);
    }

    cout << "\nIn Jagged Array Form: ";
    for (int i = 0; i < noOfStudents; i++)
    {

        cout << "\n"
             << students[i].getName() << "->";
        students[i].displayCourses();
    }

    cout << endl;
    cout << "\nEach Student's Average Marks : ";
    for (int i = 0; i < noOfStudents; i++)
    {

        cout << "\n"
             << students[i].getName() << "->";
        students[i].displayAverageMarks();
    }
    cout << endl;
    delete[] students;
}


//Old Implementation
/*

// assuming each row is a student and the no of columns in each row is their enrolled courses
//
#include <iostream>
using namespace std;

class CourseEnrolled
{
private:
    string courseName;
    float marks;

public:
    CourseEnrolled(string name = "", float marks = 0) : courseName(name), marks(marks) {}

    void setName(string name)
    {
        this->courseName = name;
    }
    void setMarks(float marks)
    {
        this->marks = marks;
    }

    float getMarks()
    {
        return marks;
    }
};

int main()
{
    CourseEnrolled **studentMarks; // each row is a seperate student
    string *studentNames;
    float *studentAverages;
    int noOfStudents;

    int *noOfCourses; // 1D array that holds in int no of courses enrolled by students
    // each row index of studentMarks corresponds to the index of noOfCourses
    // basically stores columns of jagged array

    float tempFloat;
    string tempString;

    cout << "Enter no. of students enrolled: ";
    cin >> noOfStudents;

    studentMarks = new CourseEnrolled *[noOfStudents];
    noOfCourses = new int[noOfStudents];
    studentAverages = new float[noOfStudents];

    for (int i = 0; i < noOfStudents; i++)
    {
        cout << "Enter Details of Student " << i + 1 << endl;
        cout << "Enter No of Courses Enrolled: ";
        cin >> noOfCourses[i];
        studentMarks[i] = new CourseEnrolled[noOfCourses[i]];
        for (int j = 0; j < noOfCourses[i]; j++)
        {
            cout << "Enter name of Course No " << j + 1 << " : ";
            cin >> tempString;
            studentMarks[i][j].setName(tempString);
            cout << "Enter marks in " << tempString << " : ";
            cin >> tempFloat;
            studentMarks[i][j].setMarks(tempFloat);
        }
    }

    for (int i = 0; i < noOfStudents; i++)
    {
        tempFloat = 0;
        for (int j = 0; j < noOfCourses[i]; j++)
        {
            tempFloat += studentMarks[i][j].getMarks(); // tempFloat acts as sum
            studentAverages[i] = tempFloat / noOfCourses[i];
        }
    }

    cout << "The averages of students are" << endl;
    for (int i = 0; i < noOfStudents; i++)
    {
        cout << "Student " << i + 1 << "->" << studentAverages[i] << endl;
    }

    cout << "The Jagged array now looks like" << endl;
    for (int i = 0; i < noOfStudents; i++)
    {
        for (int j = 0; j < noOfCourses[i]; j++)
        {
            cout << studentMarks[i][j].getMarks() << ", ";
        }
        cout << endl;
    }

    // Free memory for each students courses
    for (int i = 0; i < noOfStudents; i++)
    {
        delete[] studentMarks[i]; // delete each sub-array of CourseEnrolled
    }

    // Free the array of pointers to students
    delete[] studentMarks;

    // Free other dynamic arrays
    delete[] noOfCourses;
    delete[] studentAverages;
}*/
