// Lab 4-1: by Andrew Le Nguyen

#include <iostream>
using namespace std;

void heap(int arr[], int n, int i)
{
    int big = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[big])
    {
        big = left;
    }
        
    if (right < n && arr[right] > arr[big])
    {
        big = right;
    }
        
    if (big != i)
    {
        swap(arr[i], arr[big]);
        heap(arr, n, big);
    }
}

void sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heap(arr, n, i);
    }
        
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ";";
    } 
}

int main()
{
    int n;
    cin >> n; 
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }
    sort(arr, n);
    display(arr, n);
    return 0;
}