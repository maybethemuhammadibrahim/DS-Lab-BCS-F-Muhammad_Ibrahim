/*
Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary.*/

#include <iostream>
using namespace std;
/*1d array of department objects act as rows, whereas each element of this array holds another
1d array of Employee objects, fulfilling the jagged array requirement while also holding relevant
information for both objects*/

class Employee
{
    string name;
    float salary;

public:
    Employee(string name = "", float salary = 0) : name(name), salary(salary)
    {
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    float getSalary()
    {
        return salary;
    }

    string getName()
    {
        return name;
    }
};

class Department
{
private:
    string name;
    Employee *employees;
    int noOfEmployees;
    float avgSalary; // of the department

public:
    Department()
    {
        name = "";
        employees = nullptr;
        noOfEmployees = 0;
        avgSalary = 0;
    }

    string getName()
    {
        return name;
    }

    float getAvgSalary()
    {
        return avgSalary;
    }

    void allocate(int index)
    {
        string tempString;
        float tempFloat, sum = 0; // sum is for avg salary calc

        cout << "Enter name of department at (" << index << ") index: ";
        cin >> name;
        cout << "Enter number of Employees in " << name << " :";
        cin >> noOfEmployees;
        employees = new Employee[noOfEmployees];

        cout << "Enter details of employees in " << name << " :" << endl;
        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << "Enter name of employee at (" << index << ") index: ";
            cin >> tempString;
            cout << "Enter salary of " << tempString << " :";
            cin >> tempFloat;
            employees[i].setSalary(tempFloat);
            employees[i].setName(tempString);
            sum += employees[i].getSalary();
        }
        avgSalary = sum / noOfEmployees;
    }

    void calculateHighestSalary()
    {
        float highest = 0;
        int index = -1;
        for (int i = 0; i < noOfEmployees; i++)
        {
            if (employees[i].getSalary() >= highest)
            {
                highest = employees[i].getSalary();
                index = i;
            }
        }
        if (index == -1)
        {
            cout << "Some error has occured during salary calculation of " << name << endl;
            return;
        }

        cout << "The Highest salary in (" << name << ") is of " << employees[index].getName() << " at " << employees[index].getSalary() << endl;
    }

    void display()
    {
        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << "[" << employees[i].getName() << "/" << employees[i].getSalary() << "] ,";
        }
    }

    ~Department()
    {
        delete[] employees; 
        employees = nullptr;
    }
};

int main()
{

    Department *departments; // each department object contains a 1d array of employee
    // so technically this acts as a 2d jagged array
    int noOfDepartments;

    cout << "Enter no of departments : ";
    cin >> noOfDepartments;

    departments = new Department[noOfDepartments];
    for (int i = 0; i < noOfDepartments; i++)
    {
        departments[i].allocate(i + 1); // passing index
    }

    cout << "\nPrinting the jagged array" << endl;
    for (int i = 0; i < noOfDepartments; i++)
    {
        departments[i].display();
        cout << endl;
    }

    cout << "\nPrinting highest salary in each department" << endl;
    for (int i = 0; i < noOfDepartments; i++)
    {
        cout << departments[i].getName() << " :" << endl;
        departments[i].calculateHighestSalary();
    }

    //calculation of department with highest avg salary
    float highest = 0;
    int index = -1;
    for (int i = 0; i < noOfDepartments; i++)
    {
        if (departments[i].getAvgSalary() >= highest)
        {
            highest = departments[i].getAvgSalary();
            index = i;
        }
    }
    if (index == -1)
    {
        cout << "Some error has occured during avg calculation" << endl;
    }

    cout << "\nThe Department with highest average salary is (" << departments[index].getName() << ") and it is " << departments[index].getAvgSalary() << endl;

    delete[] departments;

    return 0;
}
