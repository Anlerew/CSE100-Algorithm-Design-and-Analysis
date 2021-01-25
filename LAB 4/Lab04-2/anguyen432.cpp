// Lab 4-2: by Andrew Le Nguyen

#include <iostream>
using namespace std;

int sep(int arr[], int a, int b)
{
    int x = arr[b];
    int i = (a - 1);
    for(int j = a;j <= b - 1; j++)
    {
        if(arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[b]);
    return (i + 1);
}

int randomize(int arr[],int a,int b)
{
    int  random = a + rand() % (b - a);
    swap(arr[b] ,arr[random]);
    return sep(arr, a, b);
}

void quick(int arr[], int a, int b){
    if (a < b)
    {
      int c = randomize(arr, a, b);
        quick(arr, a, c - 1);
        quick(arr, c + 1, b);
    }
}

int main() 
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    quick(arr, 0, size - 1);
    for(int i = 0; i < size; i++)
    {
        cout << arr[i]<<";";
    }
    return 0;
}