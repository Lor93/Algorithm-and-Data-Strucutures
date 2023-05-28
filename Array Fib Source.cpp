#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int fib(int a)
{
	int x = 0, y = 1, z, i;
	if (a == 0)
		return a;
	for (i = 2; i <= a; i++)
	{
		z = x + y;
		x = y;
		y = z;
	}
	return y;
}
int main()
{

	auto start = high_resolution_clock::now();
	int a = 35; 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Input " << a << endl;
	cout << "Output " << fib(a);
	cout << "\nTime: " << duration.count();

	
	return 0;
}