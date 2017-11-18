/*
 Intermediate C++ class at BMCC
 from text, p. 636  #10

 Al Curry
 July 20, 2016

Write a program that uses 3 identical arrays of 10 integers. It should display the contents
of the array, then call a function to sort it using an ascending order bubble sort, modified
to print out the array contents after each pass of the sort.  Then call a function to sort it using an 
ascending order selection sort, modified to print out the array contents after each pass of the sort. 
Use a quick sort for the 3rd copy of the array, and last the built-in sort function provided in the 
 <algorithm> library. 

 Though with such a small data set as in this exercise it does not matter, the quick sort is generally 
 considered the best, able to handle a large data set well and does not require additional space to store
 copies of the data.  

 */

#include<iostream>
#include<algorithm>

using namespace std;

void printArray(int array[], int start, int end);
void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void quickSort(int array[], int left, int right);
void swap(int i,int j, int array[]);

const int SIZE = 10;
int main()
{
	int numlist[] = { 13, 20, 25, 3, 17, 23, 5, 11, 1, 22};
	int numlist2[] = { 13, 20, 25, 3, 17, 23, 5, 11, 1, 22};
	int numlist3[] = { 13, 20, 25, 3, 17, 23, 5, 11, 1, 22};
        int numlist4[] = { 13, 20, 25, 3, 17, 23, 5, 11, 1, 22};
        
	cout << "Original array:" << endl;
	printArray(numlist, 0, SIZE);

        bubbleSort(numlist, SIZE);
        sort(begin(numlist), end(numlist));

	//print results of Bubble Sort
        cout << "1. Results after Bubble Sort:" << endl;
	printArray(numlist, 0, SIZE);

        selectionSort(numlist2, SIZE);

	//print results of Selection Sort
        cout << "2. Results after Selection Sort:" << endl;
	printArray(numlist2, 0, SIZE);

        quickSort(numlist3, 0, SIZE-1);

	//print results of Selection Sort
        cout << "3. Results after Quick Sort:" << endl;
	printArray(numlist3, 0, SIZE);     

        // print results of sort in algorithm, essentially an improved quicksort with
        // complexity O(N log(N))
        sort(begin(numlist4), end(numlist4));
        cout << "4. Results after sort from <algorithm> library:" << endl;
	printArray(numlist4, 0, SIZE); 
        
	return 0;
}
void printArray(int array[], int start, int end) {

	for (int k = start; k < end; k++)
		cout << array[k] << " " ;
	cout << endl;

}

// Note it is not necessary to pass the array by reference, as a legacy from C it is
// essentially treated as a pointer and changes in the array are preserved back
// in the main calling program.
void bubbleSort(int array[], int size)
{
	int temp;		//Temporarily stores a number

	cout << "Bubble sorting ... each pass displayed :" << endl;

	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
		printArray(array, 0, size);
	}
}
void selectionSort(int array[], int size)
{
	cout << "Selection sorting ... each pass displayed :" << endl;

	int minvalue;
	int index;

	for (int i = 0; i < size - 1; i++)
	{
		minvalue = array[i];
		index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (minvalue > array[j])
			{
				minvalue = array[j];
				index = j;
			}
		}
		array[index] = array[i];
		array[i] = minvalue;
		printArray(array, 0, size);
	}
}
void swap(int i,int j, int array[]){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quickSort(int array[], int left, int right){
    int min = (left+right)/2;
    //cout << "QS: " << left << " , " << right << "\n";

    int i = left;
    int j = right;
    int pivot = array[min];
    
    if (left == 0 && right == SIZE - 1)
      cout << "Quick sort ... each pass displayed :" << endl;

    while(left < j || i < right)
    {
        while(array[i] < pivot)
        i++;
        while(array[j] > pivot)
        j--;

        if(i <= j){
            swap(i, j, array);
            i++;
            j--;
        }
        else{
            if(left < j)
                quickSort(array, left, j);
            if(i < right )
                quickSort(array,i,right);
            return;
        }
        printArray(array, left, right);
    }
   
}
