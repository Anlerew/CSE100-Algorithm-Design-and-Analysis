#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <stack>
#define inf 9999
using namespace std;
bool go[inf];
int j=1;
void dfs_1(int n, list<int>by[], int form[], int val)
{
    j++;
    list<int>::iterator m;
    for(m = by[n].begin();m!=by[n].end();m++)
    {
        if (!go[*m])
        {
            go[*m]=true;
            dfs_1(*m,by,form,val);
        }
        if(go[*m])
        {
            j++;
        }
    }
    form[n]=j;
}
void search(list<int>t[], int k,int val,bool dis[])
{
    list <int> :: iterator m;
    for(int p =0; p<val;p++)
    {
        for(m = t[p].begin(); m != t[p].end(); ++m)
        {
            if(*m==k)
            {
                cout<<p<<endl;
                dis[k]=true;
                break;
            }
        }
    }
    if(!dis[k])
    {
        cout<<k<<endl;
    }
}
void dfs_2(int n, list<int>t[], list<int>fin[], int ins)
{
    list<int>::iterator m;
    for(m = t[n].begin();m!=t[n].end();m++)
    {
        if (!go[*m])
        {
        fin[ins].push_back(n);
            go[*m]=true;
            dfs_2(*m,t,fin,ins);
        }
    }
}
void ins(int vert, int side, list<int>by[])
{
    by[side].push_back(vert);
}
void print(int num, list<int>by[])
{
    list <int> :: iterator m;
    for(int i = 0; i<num;i++)
    {
        cout<<i<<":";
        for(m = by[i].begin(); m != by[i].end(); ++m)
        {
            cout<<*m<<"->";
        }
        cout<<";"<<endl;
    }
}
void trav(list<int>t[],list<int>by[],int val )
{
    list <int> :: iterator m;
    for(int i = 0; i<val;i++)
    {
        for(m = by[i].begin(); m != by[i].end(); ++m)
        {
             t[*m].push_back(i);
        }
    }
}
void scc(list<int>t[],int vals, int form[],list<int>fin[])
{
    for(int i =0; i<vals;i++)
    {
        if(!go[i])
        {
            dfs_2(form[i], t, fin,form[i]);
        }
    } 
}

void ord(int form[], int val, int ord[])
{
    int o =0;
    for (int i = 0; i <val;i++)
    {
        o = distance(form, max_element(form, form + val));
        ord[i]=o;
        form[o]=0;
    }
}

int main() 
{
    int rep=0;
    int val;
    cin>>val;
    int form[val];
    int q[val];
    list<int>by[val];
    list<int>t[val];
    list<int>fin[val];
    cin>>rep;
    int vert;
    int side;
    for(int l=0; l<rep;l++)
    {
    cin>> vert>>side;
        ins(side, vert, by);
    }
    trav(t,by,val);
    dfs_1(0,by,form,val);
    for (int w=0;w<val;w++)
    {
        if(!go[w])
        {
            form[w]=j+2;
        }
        go[w]=NULL;
    }
    ord(form,val,q);
    scc(t, val, q, fin);
    for (int w=0;w<val;w++)
    {
        if(!go[w])
        {
            fin[w].push_back(w);
        }
    }
    bool find[val];
    for(int z=0;z<val;z++)
    {
        search(fin, z, val,find);
    }
}