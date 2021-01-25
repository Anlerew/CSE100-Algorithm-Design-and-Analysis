//Lab 01: by Andrew Le Nguyen

#include <iostream>
using namespace std;

void print(int arr[], int val) // print function
{
  for (int i=0; i<val+1; i++)
  {
    cout << arr[i] << ";";
  }
  cout << endl;
}

void insertion(int arr[],int val) // insertion sort function
{
  int i, j, tmp;
    for(int i=1; i<val; i++) // storing current element whose left side is checked for its correct position
    {
      for (j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
        tmp = arr[j];             // moving the left value to one position forward
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;         // movine current value to correct position
      }
      print(arr,i);
    }
}

int main() // main function
{
  int size;
  cin >> size;
  int arr[size];
  for(int i=0; i<size; i++)
  {
    cin >> arr[i];
  }
  insertion(arr, size);
  return 0;
}