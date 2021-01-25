// Lab 3: by Andrew Le Nguyen

#include <iostream>
#include <climits>
using namespace std;

	int max_x_subarr(int arr[], int l, int m, int h)
    {
		int sum = 0;
        int lsum = INT_MIN;
		for (int i = m; i >= l; i--) 
        {
			sum = sum + arr[i];
			if (sum > lsum) 
            {
				lsum = sum;
			}
		}
		
		sum = 0;
        int rsum = INT_MIN;
		for (int i = m + 1; i <= h; i++) 
        {
			sum = sum + arr[i];
			if (sum > rsum) 
            {
				rsum = sum;
			}
		}
		return (lsum + rsum);
	}

	int max_subarr(int arr[], int l, int h)
    {
		int m, lsum, rsum, xsum;
		if (l == h) 
        {
			return arr[0];
		}
		else 
        {
			m = (h + l) / 2;
			lsum = max_subarr(arr, l, m);
			rsum = max_subarr(arr, m + 1, h);
			xsum = max_x_subarr(arr, l, m, h);
			if (lsum >= rsum && lsum >= xsum) 
            {
				return lsum;
			}
			else if (rsum >= lsum && rsum >= xsum) 
            {
				return rsum;
			}
			else 
            {
				return xsum;
			}
		}
	}
	
int main () 
{
	int size;
	int maxsubarr;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) 
    {
		cin >> arr[i];
	}
	maxsubarr = max_subarr(arr, 0, size - 1);
	cout << maxsubarr;
	return 0;
}