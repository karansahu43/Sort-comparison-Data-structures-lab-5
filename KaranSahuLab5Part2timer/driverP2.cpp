// Author:  Karan Sahu
// Assignment Number: Lab 5
// File Name: driver.cpp
// Course/Section: data struct
// Due Date:  11/13/18
// Instructor: Bernard Ku


#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <fstream>
#include <ctime>

#include "bubbleSort.cpp"
#include "HeapSort.cpp"
#include "insertionSort.cpp"
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "selectionSort.cpp"
#include "shellSort.cpp"
#include "RadixSort.cpp"



using namespace std;


//This function is a template function which will take parameters of a template defined array and an intger to create files to display array
//Pre condition: parrameters array and 2 integers 
//Post condition: True
template<class ItemType>
void Display(ItemType theArray[], int S, int C){
	
	cout << endl << "Creating Text files with Array string elements: " << endl;
	if(C==1)
	{
		ofstream myfile ("SortedArray.txt");
		if (myfile.is_open())
		{
			for(int i = 0; i < S; i++)
			{
				myfile << theArray[i] << endl;
			}

    	myfile.close();
   		}
	else cout << "Unable to open file";
	}
	else if(C==0)
	{
		ofstream myfile ("UnSortedArray.txt");
		if (myfile.is_open())
		{
			for(int i = 0; i < S; i++)
			{
				myfile << theArray[i] << endl;
			}

    	myfile.close();
    
    	}
	else cout << "Unable to open file";
	}
	cout << endl << "Complete(check files in folder)\n";
}


//This function is a template function which will take parameters of a template defined array and an intger to  use sort functions to sort array
//Pre condition: parrameters array and 2 integers 
//Post condition: True
template<class ItemType>
int Sorting(ItemType theArray[], int S, int selection){
	
	
	if(selection == 1)
	{
		bubbleSort<ItemType> (theArray, S);
		cout << "bubble sort ";
	}
	else if(selection == 2)
	{
		selectionSort<ItemType> (theArray, S);
		cout << "selection sort ";
	}
	else if(selection == 3)
	{
		insertionSort<ItemType> (theArray, S);
		cout << "Insertion sort ";
	}
	else if(selection == 4)
	{
		ItemType holderArray[S + 1];
		holderArray[0] = theArray[2];
    	for (int i = 0; i < S; i++)
    	{
        	holderArray[i+1] = theArray[i];
    	}
		HEAPSORT<ItemType> (holderArray, S);
		cout << "Heap sort ";
		for(int i = 0; i < S; i++)
		{
			theArray[i] = holderArray[i+1];
		}
	}
	else if(selection == 5)
	{
		shellSort<ItemType> (theArray, S);
		cout << "shell sort ";
	}
	else if(selection == 6)
	{
		mergeSort<ItemType> (theArray, 0, S -1);
		cout << "merge sort ";
	}
	else if(selection == 7)
	{
		quickSort<ItemType> (theArray, 0, S -1);
		cout << "quick sort ";
	}
	else if(selection == 8)
	{
		return 1;
	}
	else if(selection == 9)
	{
		sort(theArray, theArray+S);
		cout << "STL sort ";
	}

	
	cout << endl << "Sorted Array: ";
	return 0;
}

int selection1()
{
	int selection;
	
	cout << endl << "Which sorting method would you like to use?" << endl 
	<< "1. Bubble\n2. Selection\n3. Insertion\n4. Heap\n5. Shell\n6. Merge\n7. Quick\n8. Radix\n9. STL\n";
	cout << "which option would you like 1-9:";
	cin >> selection;
	
	return selection;
}

//The main function will create arrays find out what type the user wants for the array,
// create the array, then use all the functions to ultametly display both sorted and unsorted arrays in files
//Pre condition: True
//Post condition: return 0
int main () {
	
	long long size;
	int typechecker;
	int selection;
	clock_t t;
	int radix;

	bool driverLoop= true;
	
	while(driverLoop)
	{
		cout << endl;
		cout << "Which type of array do you want to sort?" << endl;
		cout << "1. Integer" << endl;
		cout << "2. String" << endl;
		cout << "3. Exit" << endl;
		cout << "Pick 1, 2, or 3: ";
		cin >> typechecker;
		if(typechecker==1)
		{
			size = 0;
			cout << "\n1k: type   (1000)" << endl << "50k:  type (50000)" << endl << "75k:  type (75000)" << endl << "100k: type (100000)" << endl << "250k: type (250000)" << endl << "500k: type (500000)";
			while(!(size == 1000 || size == 50000 || size == 75000 || size == 100000 || size == 250000 || size == 500000))
			{
				cout<< "\nhow big do you want the array?(type one option)";
				cin >> size;
			}
			
			int* holderI = new int[size];
  
			for(int i = 0; i < size; i++)
 			{
 			   holderI[i] = (rand() % 100000000) + 1;
			}
  
	
			cout << endl << "Original Array: ";
			Display(holderI, size, 0);
			selection = selection1();
			
		//	for(int i = 1; i<10;i++)
		//	{
			//	selection = i;
				t = clock();
				radix = Sorting<int> (holderI, size, selection);
				if(radix == 1)
				{
					radixsort(holderI, size);
					cout << "radix sort ";
					cout << endl << "Sorted Array: ";
				}
				t = clock() - t;
				printf(": it took %d clicks(%f seconds).\n",t,((float)t/CLOCKS_PER_SEC));
				cout << endl;
		//	}
			Display(holderI, size, 1);
			delete [] holderI;
  			holderI = nullptr;
		}
		else if(typechecker==2)
		{
			size = 0;
			cout << "\n100k: type (100000)" << endl << "250k: type (250000)" << endl << "450k: type (450000)";
			while(!( size == 100000 || size == 250000 || size == 450000))
			{
				cout<< "\nhow big do you want the array?(type one option)";
				cin >> size;
			}
			
			string holderS[size];
			
			ifstream myfile ("LastName2010.txt");
			if (myfile.is_open())
			{
		    	for(int i = 0; i < size; i++ )
		    	{
		      		getline (myfile,holderS[i]);
		    	}
			}
			else 
				cout << "Unable to open the file";
			myfile.close();
			cout << endl << "Original Array: ";
			Display(holderS, size, 0);
			selection = selection1();
		//	for(int i = 1; i<10;i++)
		//	{
			//	selection = i;
				t = clock();
				radix = Sorting<string> (holderS, size, selection);
				if(radix == 1)
				{
					radixSort(holderS, size);
					cout << endl << "Sorted Array: ";
				}				
				t = clock() - t;

				printf(": it took %d clicks(%f seconds).\n",t,((float)t/CLOCKS_PER_SEC));
		//	}
			Display(holderS, size, 1);
		}
		if(typechecker==3)
		{
			driverLoop = false;
		}
	}
	return 0;
}

// 		Sample output
//
//	345*+67*8+9*+ = 473
//
//	1234*+5/- = -1
//
//	12+43-* = 3
//
//	48+65-*32-22+*/ = 3
//
//	234+* = 14
//
//	72/ = 3
//
//	512+4*+3- = 14
//
//	72%  Malformed expression - invalid operator detected
//
//	7*22+  Malformed expression - invalid postfix
//
//	A2/  Malformed expression - invalid operand character detected
//
//	72//  Malformed expression - invalid postfix
//
//	(23-  Malformed expression - invalid operand character detected


