// Lab 11: by Andrew Le Nguyen
// Help from Andres Rios and PALS
#include<iostream>
#include<vector>
using namespace std;
int mst(int base, vector<pair<int, int>> by[],int l) //Help from geekforgeek on understanding vector pairs and its use cases
{   
    int seq[l];
    int source[l];
    bool join[l];
    for (int i=0;i<l;i++) 
    {
        seq[i] = 2147483647; 
        join[i] = false;
    }
    seq[base] = 0; //starts at zero
    source[base] = -1; // base of the mst
    for(int i=0;i<l-1;i++)
    {
        int h;
        int s = 2147483647;
        for (int j=0;j<l;j++)
        {
            if (join[j] == false && seq[j] < s)
            {
                s = seq[j];
                h = j;
            }
        }
        join[h] = true;
        for(int j=0;j<by[h].size();j++)
        { // selected sides step by step in increasing order from start
            int g = by[h][j].first; //"first and second" used to access 1st and 2nd elements of pair
            int f = by[h][j].second;
            if(join[f]==false && g<seq[f])
            {
                source[f] = h;
                seq[f] = g;
            }
        }
    }
    for(int i=1;i<l;i++)
    {
        cout << source[i] << endl; // print results
    }
}
int main() // Help from hackerearth.com
{   // https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
    int l;  //leaves
    int s;  //sides
    int a;
    int b;
    int c;
    cin >> l;
    cin >> s;
    vector<pair<int, int>> by[l];
    for(int i=0;i<s;i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;
        by[a].push_back(make_pair(c, b)); //Entering values in vector of pairs
        by[b].push_back(make_pair(c, a));
    }   // Sort the sides in ascending order 
    mst(0,by,l); // calls mst 
    return 0;
}

/* 
Initialize a min-priority queue Q. 
        for all u ∈ V do 
            u.key = ∞. 
            u.π = NIL. 
            Insert (Q,u). 
        end for 
            Decrease-key(Q,r,0).
            while Q 6= ∅ do
                u = Extract-Min(Q).
                for all v ∈ Adj[u] do
                    if v ∈ Q and w(u,v) < v.key then
                        v.π = u. 
                        Decrease-Key(Q,v,w(u,v)).
                    end if
                end for 
            end while
*/