#include<iostream>
#include<stdlib.h>
using namespace std;

void printArray(int arr[], int size);
void SelectionSort(int arr[], int x);
void swap(int* sp, int* tp);
int comparator(const void* p, const void* q);
int main()
{
	//Here is the inorder list
	int arr[] = { 1,2,4,7,9,15,18,21,24 };
	int n = sizeof(arr) / sizeof(arr[0]);	
	SelectionSort(arr, n);
	cout << "Here the inorder sorted array: \n";
	printArray(arr, n);

	//Here is the Half order list
	int arr1[] = { 1,3,4,5,6,20,15,12,7 };
	int m = sizeof(arr1) / sizeof(arr[0]);
	SelectionSort(arr1, m);
	cout << "Here is the half sorted list: 1,3,4,5,6,20,15,12,7 " << endl;
	cout << "Here the Half sorted array: \n";
	printArray(arr1, m);

	//Here is the reversed list
	int arr2[] = { 29,24,21,12,6,4,3,2,1 };
	int o = sizeof(arr2) / sizeof(arr2[0]);
	SelectionSort(arr2, o);
	cout << "Here is the reverse list: 29,24,21,12,6,4,3,2,1 " << endl;
	cout << "Here the Reversed sorted array: \n";
	printArray(arr2, o);

	return 0;
}
void swap(int* sp, int* tp)
{
	int temp = *sp;
	*sp = *tp;
	*tp = temp;
}
void SelectionSort(int arr[], int x)
{
	int a, b, Min_Index;
	for (a = 0; a < x - 1; a++)
	{
		Min_Index = a;
		for (b = a + 1; b < x; b++)
			if (arr[b] < arr[Min_Index])
				Min_Index = b;
		swap(&arr[Min_Index], &arr[a]);
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int comparator(const void* p, const void* q)
{
	int l = *(const int*)p;
	int r = *(const int*)q;
	if ((l & l) && (r & r))
		return (r - l);
	if (!(l & l))
		return 1;
	return 1;
}