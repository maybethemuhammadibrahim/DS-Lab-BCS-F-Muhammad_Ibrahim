/*
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.
*/
/*Used Prettier(Vs Code extention for formatting code)*/
#include <iostream>
using namespace std;

void addNewMonths(float *&arr, int &elements)
{
    int additional;
    cout << "Enter additional number of months: ";
    cin >> additional;

    float *temp = new float[elements];
    for (int i = 0; i < elements; i++)
    {
        temp[i] = arr[i];
    }

    delete[] arr;

    arr = new float[elements + additional];
    for (int i = 0; i < elements; i++)
    {
        arr[i] = temp[i];
    }

    delete[] temp;

    for (int j = 0; j < additional; j++)
    {
        cout << "Enter expenses for month " << elements + j + 1 << " : ";
        cin >> arr[elements + j];
    }

    elements += additional;
}

void displayTotalExpenses(float *arr, int elements)
{
    float total = 0;
    for (int i = 0; i < elements; i++)
    {
        total += arr[i];
    }
    cout << "Total Expenses = " << total << endl;
}

void displayAverageExpenses(float *arr, int elements)
{
    float total = 0;
    for (int i = 0; i < elements; i++)
    {
        total += arr[i];
    }
    cout << "Average Expenses = " << total / elements << endl;
}

int main()
{
    float *expenses;
    int noOfMonths = 0;

    cout << "Enter number of months(n) to store expenses for: ";
    cin >> noOfMonths;

    expenses = new float[noOfMonths];
    for (int i = 0; i < noOfMonths; i++)
    {
        cout << "Enter expenses for month " << i + 1 << " : ";
        cin >> expenses[i];
    }

    int input = -1;
    do
    {
        cout << "\nEnter operation to perform\n"
             << "(1 - Resize and add expenses for more months)\n"
             << "(2 - Compute total expenses)\n"
             << "(3 - Compute average expenses)\n"
             << "(0 - Exit)" << endl;
        cin >> input;

        switch (input)
        {
        case 1:
            addNewMonths(expenses, noOfMonths);
            break;
        case 2:
            displayTotalExpenses(expenses, noOfMonths);
            break;
        case 3:
            displayAverageExpenses(expenses, noOfMonths);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (input != 0);

    delete[] expenses;
    return 0;
}
