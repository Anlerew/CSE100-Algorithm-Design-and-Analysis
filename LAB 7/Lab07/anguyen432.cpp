// Lab 07: by Andrew Le Nguyen
// Help from Andres Rios

#include <iostream>
using namespace std;
int b;
int rod(int h[],int x)
{
    int c[x + 1];
    int d[x + 1];
    int e = x;
    c[0] = 0;
    for(int j = 1; j <= x; j++)
    {
        b = 0;
        for(int i = 1; i <= j; i++)
        {
            if(b < h[i] + c[j - i])
            {
                b = h[i] + c[j - i];
                d[j] = i;
            }
        }
        c[j] = b;
    }
    cout << c[x] << endl;
    while (e > 0)
    {
        cout << d[e] <<" ";
        e = e - d[e];
    }
    return -1;

}
int main()
{
    int len;
    cin >> len;
    int g[len + 1];
    g[0] = 0;
    for(int i = 1; i < len + 1; i++)
    {
        cin >> g[i];
    }
    cout << rod(g, len) << endl;
    return 0;
}