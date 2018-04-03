/*
Lab7.cpp
Sash STramel
Lab 7-Sorting Speed
Cosc 2030 Data Structure
2 April 2017
*/


#include "RandomUtilities.hpp"
#include "ContainerPrinting.hpp"
#include "MacTimer.hpp"
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BubbleSort(vector<double>& number)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < (number.size() - 1); i++)
        {
            if (number[i] > number[i + 1])
            {
                double temp = number[i];
                number[i] = number[i + 1];
                number[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

void InsertionSort(vector<double>& number)
{
    for (int i = 1; i < number.size(); i++)
    {
        double current = number[i];
        int j = (i - 1);
        
        while (j >= 0 && (number[j] > current))
        {
            double temp = number[j];
            number[j] = number[j + 1];
            number[j + 1] = temp;
            j--;
        }
        current = number[j + 1];
    }
}

void SelectionSort(vector<double>& number)
{
    for (int i = 0; i < (number.size() - 1); i++)
    {
        int minimum = i;
        
        for (int j = (i + 1); j < number.size(); j++)
        {
            if (number[j] < number[minimum])
            {
                minimum = j;
            }
        }
        
        if (minimum != i)
        {
            double temp = number[i];
            number[i] = number[minimum];
            number[minimum] = temp;
        }
    }
}


void QuickSort(vector<double>& number)
{
    int i = number.front();
    int j = number.back();
    int pivot = number[(number.front() + number.back()) / 2];
    int temp;
    
    while (i <= j)
    {
        while (number[i] < pivot)
        {
            i++;
        }
        while (number[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
            i++;
            j--;
        }
    };
    
    if (number.front() < j)
    {
        QuickSort(number);
    }
    if (number.back() > i)
    {
        QuickSort(number);
    }
}

vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
    vector<double> theList;
    for (size_t i = 0; i < listSize; ++i)
    {
        theList.push_back(randReal(minNum, maxNum));
    }
    
    return theList;
}

// Testing
int main()
{
    while (true)
    {
        cout << "Enter size for numbers: ";
        int n = 0;
        cin >> n;
        if (n <= 0)
            break;
        cout << "Enter seed for rand: ";
        unsigned int seed;
        cin >> seed;
        srand(seed);
        
        //Construct a sorted list
        Timer get;
        get.start();
        vector<double> numbers = getNums(n, -n ,n);
        get.stop();
        cout << "Constructed in " << get() << " seconds"
        << endl;

        if (n < 10)
            cout << &numbers << endl << endl;

        // Report
//        Timer time;
//        time.start();
//        sort(numbers.begin(), numbers.end());
//        BubbleSort(numbers);
//        InsertionSort(numbers);
//        SelectionSort(numbers);
//        QuickSort(numbers);
//        cout << &numbers << endl << endl;
//        time.stop();
//        cout << "calculated in " << time() << " seconds"
//        << endl << endl;
        
        if (n < 10)
            cout << numbers << endl << endl;
        

//        Timer time;
//        time.start();
//        SelectionSort(numbers);
//        cout << numbers << endl << endl;
//        time.stop();
//        cout << "calculated in (SelectionSort) " << time() << " seconds"
//        << endl << endl;
        

        Timer time;
        time.start();
        QuickSort(numbers);
        cout << numbers << endl << endl;
        time.stop();
        cout << "calculated in (quickSort)" << time() << " seconds"
        << endl << endl;
////
//        Timer time;
//        time.start();
//        InsertionSort(numbers);
//        cout << numbers << endl << endl;
//        time.stop();
//        cout << "calculated in(InsertionSort) " << time() << " seconds"
//        << endl << endl;
    }
    return 0;
}
