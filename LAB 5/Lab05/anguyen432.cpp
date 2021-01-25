//Lab 05: by Andrew Le Nguyen
//Help from Andres Rios and PALS
//Reference help from Charles Tolentino via Skype with understanding and examples.

#include <iostream>
#include <vector>
#define len 10
using namespace std;

vector<vector<int>> count(vector<vector<int>> cont, vector<int> vtemp) 
{
    vector<int> C(len,0);
    vector<vector<int>> vnew;
    vnew.resize(vtemp.size());
    
    for(int i = 0; i < vtemp.size(); i++)
        C[vtemp[i]]++;
    for( int i = 1; i < C.size(); i++)
        C[i] += C[i-1];
    for (int i = 0; i < vtemp.size(); i++)
        vnew[i].resize(len);
    for(int i = vtemp.size()-1; i >= 0; i--) 
    {
        swap(vnew[C[vtemp[i]]-1],cont[i]);
        C[vtemp[i]] -= 1;
    }
    return vnew;
}

void radix(vector<vector<int>> cont) 
{
    for (int i = len-1; i >= 0; i--) 
    {
        vector<int> vtemp;
        for (int j = 0; j < cont.size(); j++ )
            vtemp.push_back(cont[j][i]);
        cont = count(cont,vtemp);
    }
    
    for(int i = 0; i < cont.size(); i++)
    {
        for (int j = 0; j < cont[i].size(); j++)
        {
            cout << cont[i][j] << ";";
        }
        cout << endl;
    }
    
}

int main(int argc, const char * argv[]) 
{
    vector<vector<int>> cont;
    int n;
    int sizev = 0;
    cin >> sizev;
    cont.resize(sizev);
    for(int i = 0; i < sizev; i++) 
    {
        for(int j = 0; j < len; j++) 
        {
            cin >> n;
            cont[i].push_back(n);
        }
    }
    radix(cont);
    return 0;
}