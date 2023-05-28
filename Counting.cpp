#include<iostream>
#include<ctime>
using namespace std;

void countSort(int arr[], int size);
void printArray(int arr[], int size);

int main() {
	time_t seconds;
	seconds = time(NULL);
	int array[] = { 4, 2, 2, 8, 3, 3, 1, 8, 0, 9, 4, 7  };
	int n = sizeof(array) / sizeof(array[0]);
	cout << "Here is the unsorted list: 4, 2, 2, 8, 3, 3, 1, 8, 0, 9, 4, 7 \n";
	countSort(array, n);
	printArray(array, n);
	cout << "Time in seconds: " << seconds;
}
void countSort(int array[], int size) {
	int output[12];
	int input[12];
	int max = array[0];

	for (int i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}

	for (int i = 0; i <= max; ++i) {
		input[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		input[array[i]]++;
	}

	for (int i = 1; i <= max; i++) {
		input[i] += input[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		output[input[array[i]] - 1] = array[i];
		input[array[i]]--;
	}

	// Copy the sorted elements into original array
	for (int i = 0; i < size; i++) {
		array[i] = output[i];
	}
}
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
