/*
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day.
*/
#include <iostream>
using namespace std;

int main()
{
    float **temps, *avgTemps, sum = 0;
    // n(days will be rows), m(times in a day will be columns)
    int n, *m;
    // assuming jagged 2D array as m can vary across different dates

    cout << "Enter no of days for which temperature data is available : ";
    cin >> n;
    temps = new float *[n];
    m = new int[n];
    avgTemps = new float[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter no of reading(s) for day no " << i + 1 << " : ";
        cin >> m[i];
        temps[i] = new float[m[i]];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter data for day no " << i + 1 << " : " << endl;
        sum = 0;
        for (int j = 0; j < m[i]; j++)
        {
            cout << "Enter reading no " << j + 1 << " : ";
            cin >> temps[i][j];
            sum += temps[i][j];
        }
        avgTemps[i] = sum / m[i];
    }

    cout << "The average temperatures are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Day: " << i + 1 << ": " << avgTemps[i] << endl;
    }

    // hottest, coldest
    float maxTemp = avgTemps[0], minTemp = avgTemps[0];
    int maxDay = 0, minDay = 0;

    for (int i = 1; i < n; i++)
    {
        if (avgTemps[i] > maxTemp)
        {
            maxTemp = avgTemps[i];
            maxDay = i;
        }
        if (avgTemps[i] < minTemp)
        {
            minTemp = avgTemps[i];
            minDay = i;
        }
    }

    cout << "Hottest day: day " << maxDay + 1 << " with avg temp " << maxTemp << endl;
    cout << "Coldest day: day " << minDay + 1 << " with avg temp " << minTemp << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] temps[i];
    }
    delete[] temps;
    delete[] avgTemps;
    delete[] m;
}
