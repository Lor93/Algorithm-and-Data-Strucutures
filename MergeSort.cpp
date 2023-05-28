#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int* sp, int* tp);
void selectionSort(int array[], int x);
void mergeSort(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);

int main()
{
	//Here is the forted list function
	const int array_size = 10;
	//auto start = high_resolution_clock::now();
	int array[array_size] = { 1,2,4,7,9,11,15,21,24,30};
	cout << "Original Array:\n";
	for (int i = 0; i < array_size; i++)
		cout << " " << array[i];
	mergeSort(array, 0, array_size - 1);
	cout << "\nSorted array: \n";
	for (int i = 0; i < array_size; i++)
		cout << " " << array[i];
	/*auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	cout << "Excution time is: " << duration.count() << " seconds" << endl;*/


	//Here is the Haf Sorted array funtion
	//auto start = high_resolution_clock::now();
	int array1[array_size] = { 1,4,5,6,20,8,9,11,12,15 };
	cout << "\nOriginal Array:\n";
	for (int i = 0; i < array_size; i++)
		cout << " " << array1[i];
	mergeSort(array1, 0, array_size - 1);
	cout << "\nHalf Sorted array: \n";
	for (int i = 0; i < array_size; i++)
		cout << " " << array1[i];
	/*auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	cout << "Excution time is: " << duration.count() << " seconds" << endl;*/


	//Here is the reversed list function
	//auto start = high_resolution_clock::now();
	int array2[array_size] = { 24,21,15,12,6,4,3,2,1 };
	cout << "\nOriginal Array:\n";
	for (int i = 0; i < array_size; i++)
		cout << " " << array2[i];
	mergeSort(array2, 0, array_size - 1);
	cout << "\nReversed Sorted array: \n";
	for (int i = 0; i < array_size; i++)
		cout << " " << array2[i];
	/*auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	cout << "\nExcution time is: " << duration.count() << " seconds" << endl;*/



	return 0;
}
void swap(int* sp, int* tp)
{
	int temp = *sp;
	*sp = *tp;
	*tp = temp;
}
void selectionSort(int array[], int x)
{
	int a, b, Min_Index;
	for (a = 0; a < x - 1; a++)
	{
		Min_Index = a;
		for (b = a + 1; b < x; b++)
			if (array[b] < array[Min_Index])
				Min_Index = b;
		swap(&array[Min_Index], &array[a]);
	}
}
void mergeSort(int array[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);
	merge(array, left, mid, right);
}
void merge(int array[], int left, int mid, int right)
{
	int leftIndex = left;
	int rightIndex = mid + 1;
	int* tempArray = new int[right - left + 1];
	for (int i = 0; i <= right - left; i++) {
		if (leftIndex <= mid && rightIndex <= right) {
			tempArray[i] = ((array[leftIndex] < array[rightIndex]) ? array[leftIndex++] : array[rightIndex++]);
		}
		else {
			if (leftIndex > mid) {
				tempArray[i] = array[rightIndex++];
			}
			else if (rightIndex > right) {
				tempArray[i] = array[leftIndex++];
			}
		}
	}
	for (int i = left; i <= right; i++) {
		array[i] = tempArray[i - left];
	}
	delete[] tempArray;
}
void printArray(int* array, int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}