// Lab 08: By Andrew Le Nguyen
// Help from Andres Rios
// pseudocode from Introduction to Algorithms Second Edition
#include <iostream>
using namespace std;

void print_optimal_parenthesis(int i, int j, int n, int* s, int &t) // Print-Optimal-Parens from book pg 338
{
    if (i == j)
    {
        cout << 'A' << t++;
    }
    else
    {
        cout << "(";
        print_optimal_parenthesis(i, *((s + i * n) + j), n, s, t);
        print_optimal_parenthesis(*((s + i * n) + j) + 1, j, n, s, t);
        cout << ")";
    } 
}

void matrix_chain_order(int p[], int n) //Matrix-Chain-Order Algorithm from book pg 336 and lecture notes
{
    int m[n][n];
    int s[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = 2147483647;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    int t = 0;
    cout << m[1][n - 1] << endl;
    print_optimal_parenthesis(1, n - 1, n, (int *)s, t);
    cout << endl;
}

int main()
{
    int n, i;
    cin >> n;
    int *arr = new int[n + 1];
    for (i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    matrix_chain_order(arr, n + 1);
    return 0;
}