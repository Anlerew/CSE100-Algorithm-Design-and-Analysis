// Lab 02: by Andrew Le Nguyen

#include <iostream>
using namespace std;

void merge(int arr[], int l, int  m, int h){
    int *temp = new int[h-l+1];
    int i = l, j = m + 1;
    int k = 0;
    while(i <= m && j <=h)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= m)
        temp[k++] = arr[i++];
    while(j <= h)
        temp[k++] = arr[j++];
    for(k = 0, i = l; i <= h; ++i, ++k)
        arr[i] = temp[k];
}
void sort(int arr[], int l, int h)
{
    int m;
    if(l<h)
    {
        m = (l+h) >> 1;
        sort(arr, l, m);
        sort(arr, m+1, h);
        merge(arr, l, m, h);
    }
}
void merge(int arr[], int arr_size)
{
    sort(arr, 0, arr_size-1);
}

int main()
{
  int size;
  cin >> size;
  int arr[size];
  for(int i=0; i<size; i++)
  {
    cin >> arr[i];
  }
  sort(arr, 0, size-1);
  for (int i=0; i<size;i++)
  {
    cout << arr[i] << ";";
  }
  return 0;
}