#include<iostream>
#include<ctime>
using namespace std;

int getMax(int arr[], int x);
void countSort(int arr[], int z, int rep);
void radixSort(int arr[], int x);
void print(int arr[], int n);

int main()
{
	int arr_size = 100;
	int increment = 1000;
	const int MAXRANGE = 100000;
	int array[MAXRANGE];
	bool run = 1;
	char option;
	while (run) {
		cout << "Enter size: ";
		cin >> arr_size;

		cout << "Average case\n";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < arr_size; j++) {
				array[j] = rand() % 1000;
			}
			//SelectionSort(array, arr_size);
			radixSort(array, arr_size);
			
		cout << "Continue (y/n)? ";
		cin >> option;
		if (option != 'y') run = 0;
	}
	return 0;
}
int getMax(int arr[], int x)
{
	int gm = arr[0];	
	for (int i = 1; i < x; ++i)	
		if (arr[i] > gm)
			gm = arr[i];
	return gm;
}
void countSort(int arr[], int g, int rep)
{
	int output[10];	// out put array
	int count[10] = { 0 };
	int i;
	for ( i = 0; i < g; i++)
		count[(arr[i] / rep) % 10]
		++;
	for ( i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	for (i = g - 1; i >= 0; i--) {
		output[count[(arr[i] / rep) % 10] - 1] = arr[i];
		count[(arr[i] / rep) % 10]--;
	}
	for (i = 0; i < g; i++) {
		arr[i] = output[i];
	}
}
void radixSort(int arr[], int x)
{
	int a = getMax(arr, x);
	
	for (int rep = 1; a / rep > 0; rep *= 10)
	{
		countSort(arr, x, rep);
	}
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}