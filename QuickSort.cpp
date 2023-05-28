#include<iostream>
#include<chrono>
#include <time.h>
using namespace std;

void quickSort(int arr[], int p, int r);
void quick_sort(int arr[], int low, int high);
void quick_Sort(int arr[], int low, int high);
int partition2(int arr[], int low, int high);
int partition1(int arr[], int low, int high);
void partition3(int arr[], int low, int high,int &i, int &j);
void printArray(int arr[], int size);

int main()
{
	int arr_size = 100000;
	const int MAXRANGE = 5000000;
	int array[MAXRANGE];
	time_t start, ending;
	double second;
	std::chrono::system_clock::time_point startTime, endTime;				// The quicksort take the last element
	for (int i = 0; i < arr_size; i++) {
		array[i] = rand() % 50000;
		printf(" %i", array[i]);
	}
	startTime = std::chrono::system_clock::now();
	quickSort(array, 0, arr_size - 1);
	//quick_sort(array, 0, arr_size - 1);
	//quick_Sort(array, 0, arr_size - 1);
	cout << "\nSorted Array\n";
	endTime = std::chrono::system_clock::now();
	printArray(array, arr_size);
	cout << float(std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count()) << "\n";
	

	/*std::chrono::system_clock::time_point startTime, endTime;
	for (int i = 0; i < arr_size; i++) {
		array[i] = rand() % 10;
		printf(" %i", array[i]);
	}
	startTime = std::chrono::system_clock::now();
	//quickSort(array, 0, arr_size - 1);
	quick_sort(array, 0, arr_size - 1);
	//quick_Sort(array, 0, arr_size - 1);
	cout << "\nSorted Array\n";
	endTime = std::chrono::system_clock::now();
	printArray(array, arr_size);
	cout << float(std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count()) << "\n";*/
	
	/*time(&start);			//The quicksort take the first element 
	for (int i = 0; i < arr_size; i++) {
		array[i] = rand() % 10;
		printf(" %i", array[i]);
	}
	
	
	//quickSort(array, 0, arr_size - 1);
	//quick_sort(array, 0, arr_size - 1);
	quick_Sort(array, 0, arr_size - 1);
	time(&ending);
	cout << "\nSorted Array\n";
	
	printArray(array, arr_size);
	second = difftime(ending, start);
	printf("Difference in time is %.2f seconds ", second);*/
	/*int sec;
	time_t time1, time2;

	// Current time
	time(&time1);
	for (sec = 1; sec <= 6; sec++)
		

	// time after sleep in loop.
	time(&time2);
	printf("Difference is %.2f seconds",
		difftime(time2, time1));*/
	return 0;
}
void swap(int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition1(int arr[], int low, int high)	//This partition take the last element as pivot
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partition2(int arr[], int low, int high)	//This partition take the firt element as pivot
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;
	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);
			if (i >= j)
				return j;
			swap(arr[i], arr[j]);
	}
}
void partition3(int arr[], int low, int high, int &i, int &j)
{
	if (high - low <= 1)			// This take the array at 1) array[l...i], 2) array[i+1...j-1], and 3)array[j...r]
	{
		if (arr[high] < arr[low])
			swap(&arr[high], &arr[low]);
		i = low;
		j = high;
		return;
	}
	int mid = low;
	int pivot = arr[high];
	while (mid <= high) {
		if (arr[mid] < pivot)
			swap(&arr[low++], &arr[mid++]);
		else if (arr[mid] == pivot)
			mid++;
		else if (arr[mid] > pivot)
			swap(&arr[mid], &arr[high--]);
	}
	i = low - 1;
	j = mid;
}
void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int part = partition1(arr, low, high);
		quick_sort(arr, low, part - 1);
		quick_sort(arr, part + 1, high);
	}
}
void quickSort(int arr[], int p, int r)		// The quicksort take the last element
{
	if (p >= r)
		return;
	int i;
	int j;
	partition3(arr, p, r, i, j);
	quickSort(arr, p, i);
	quickSort(arr, j, r);

}
void quick_Sort(int arr[], int low, int high)	//The quicksort take the first element 
{
	if (low < high) {
		int part = partition2(arr, low, high);
		quick_Sort(arr, low, part);
		quick_Sort(arr, part + 1, high);
	}
}
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
