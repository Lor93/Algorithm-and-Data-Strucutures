#include <iostream>
using namespace std;

void printParent(int s[], int i, int j, int n, char& name);
void matrixChainOrder(int p[], int n);

int main() {
    int arr[] = {10,20,30,40,30,50,20};
    int arr1[] = {4,10,3,12,20,7};
    int arr2[] = {30,35,15,5,10,20,25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int n1 = sizeof(arr1) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(arr[0]);
    matrixChainOrder(arr, n-1);
    matrixChainOrder(arr1, n1-1);
    matrixChainOrder(arr2, n2-1);
    return 0;
}

void matrixChainOrder(int p[], int n) {
    int* m = new int[n * n];
    int* s = new int[n * n];

    for (int i = 0; i < n; i++)
    {
        m[i + i * n] = 0;
    }

    for (int L = 1; L < n; L++)
    {
        for (int i = 0; i < n - L; i++)
        {
            int j = i + L;
            m[i + j * n] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i + k * n] + m[(k + 1) + j * n] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i + j * n])
                {
                    m[i + j * n] = q;
                    s[i + j * n] = k;
                }
            }
        }
    }

    /*for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++)
            cout << m[i + j * n] << ", ";
        cout << endl;*/
    //}

    char name = 'A';
    printParent(s, 0, n-1, n, name);
    cout << "\nOptimal Cost is: " << m[n * (n - 1)] << endl;
}
void printParent(int s[], int i, int j, int n, char& name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    printParent(s,i,s[i+j*n],n, name);
    printParent(s,s[i+j*n] +1,j,n, name);
    cout << ")";
}
