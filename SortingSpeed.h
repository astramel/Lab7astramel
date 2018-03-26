//Header file for Sorting Speeds Lab
//Created by: Rafer Cooley 3/25/18

#include "RandomUtilities.h"
#include<vector>
#include<algorithm>
#include<iostream>
// From Dr. Tom Bailey's Lab6 SortedDriver.cpp
// *modified*
// post: a vector of listSize random doubles from
//         the range minNum to maxNum has been returned.

using std::vector;
using std::cout;
using std::endl;

vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}
	return theList;
}

//TODO: implement quicksort here
//return a sorted vector of doubles
vector<double> QuickSort(vector<double>& vec1, vector<double>& vec2){
  cout << "TODO: implement QuickSort" << endl;
}
//TODO: implement quicksort here
//return a sorted vector of doubles
vector<double> BubbleSort(vector<double>& vec1, vector<double>& vec2){
  cout << "TODO: implement BubbleSort" << endl;
}
//TODO: implement quicksort here
//return a sorted vector of doubles
vector<double> InsertionSort(vector<double>& vec1, vector<double>& vec2){
  cout << "TODO: implement InsertionSort" << endl;
}
//TODO: implement SelectionSort here
//return a sorted vector of doubles
vector<double> SelectionSort(vector<double>& vec1, vector<double>& vec2){
  cout << "TODO: implement SelectionSort" << endl;
}
