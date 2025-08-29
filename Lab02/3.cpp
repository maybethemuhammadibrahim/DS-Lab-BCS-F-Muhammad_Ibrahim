#include <iostream>
using namespace std;
/*
Task #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks.

*/

//assuming each row is a student and the no of columns in each row is their enrolled courses
//
class CourseEnrolled {
    private:
    string courseName;
    float marks;

    public:
    CourseEnrolled(string name = "", float marks = 0) : courseName(name), marks(marks) {}

    void setName(string name) {
        this->courseName = name;
    }
    void setMarks(float marks) {
        this->marks = marks;
    }

    float getMarks() {
        return marks;
    }
     
};


int main() {
   CourseEnrolled **studentMarks;//each row is a seperate student
   string *studentNames;
   float *studentAverages;
int noOfStudents;

int *noOfCourses;//1D array that holds in int no of courses enrolled by students
//each row index of studentMarks corresponds to the index of noOfCourses
//basically stores columns of jagged array

float tempFloat; string tempString;

   cout << "Enter no. of students enrolled: ";
   cin >> noOfStudents;
   
   studentMarks = new CourseEnrolled*[noOfStudents];
   noOfCourses = new int[noOfStudents];
   studentAverages = new float[noOfStudents];

    for(int i = 0; i < noOfStudents; i++) {
        cout << "Enter Details of Student " << i+1 << endl;
        cout << "Enter No of Courses Enrolled: ";
        cin >> noOfCourses[i];
        studentMarks[i] = new CourseEnrolled[noOfCourses[i]];
        for(int j = 0 ; j < noOfCourses[i]; j++) {
            cout << "Enter name of Course No "<< j+1 <<" : ";
            cin >> tempString;
            studentMarks[i][j].setName(tempString);
            cout << "Enter marks in " << tempString << " : ";
            cin >> tempFloat;
            studentMarks[i][j].setMarks(tempFloat);
        }
    }

    
    for (int i = 0; i < noOfStudents; i++) {
        tempFloat = 0;
        for(int j = 0; j < noOfCourses[i] ; j++){
            tempFloat += studentMarks[i][j].getMarks();//tempFloat acts as sum
            studentAverages[i] = tempFloat/noOfCourses[i];
        }
    }

    cout << "The averages of students are" << endl;
    for (int i = 0; i < noOfStudents; i++) {
        cout << "Student " << i+1 << "->" << studentAverages[i] << endl;
    }


    cout << "The Jagged array now looks like" << endl;
     for(int i = 0; i < noOfStudents; i++) {
        for(int j = 0; j < noOfCourses[i]; j++) {
            cout << studentMarks[i][j].getMarks() << ", ";
        }
        cout << endl;
    }


    // Free memory for each students courses
for (int i = 0; i < noOfStudents; i++) {
    delete[] studentMarks[i];  // delete each sub-array of CourseEnrolled
}

// Free the array of pointers to students
delete[] studentMarks;

// Free other dynamic arrays
delete[] noOfCourses;
delete[] studentAverages;


}
