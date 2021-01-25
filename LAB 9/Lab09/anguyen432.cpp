//Lab 09: by Andrew Le Nguyen
// Help from Andres Rios
#include<iostream>
#include <deque>
#include<map>
#include<queue>
#include<string>
using namespace std;

map<char, string>t;
struct node 
{
    char sym;
    double fre;
    node* l;
    node* r;
};
struct nodecomp
{
    bool operator()(node* l, node* r)
    {
        return (l->fre > r->fre);
    }
};

priority_queue<node *, deque<node *>, nodecomp> m;

node* get(char sym, double fre)
{
    node* n1= new node();
    n1->fre=fre;
    n1->sym=sym;
    n1->l=NULL;
    n1->r=NULL;
    return n1;
}
node* clear()
{
    node* n2= new node();
    n2->l=NULL;
    n2->r=NULL;
    n2->l=NULL;
    n2->fre=NULL;
    return n2;
}

static void enc(node *m, string e, int i) 
{
    char sym[]={'A','B','C','D','E','F'};
    if (m==NULL) 
    {
        return;
    }
    
    if (m->sym == sym[i]) 
    {
        t.insert(make_pair (sym[i],e));
    }
    if (m->sym!= sym[i])
    {
    enc(m->l, e + "0", i);
    enc(m->r, e + "1", i);
    }
};

void huff()
{
    node *x= clear();
    node *y= clear();
    node *z=clear();
    for(int p=6; p!=1;p--)
    {
        x = m.top();
        m.pop();
        y = m.top();
        m.pop();
        z = get(' ', (x->fre + y->fre));
        z->l = x;
        z->r = y;
        m.push(z);
    }
}


int main()
{
    double fre;
    int x=0;
    while (x!=6)
    {
      
        cin>>fre;
        if (x==0)
        {
            m.push(get('A', fre));
        }
        if (x==1)
        {
            m.push(get('B', fre));
        }
        if (x==2)
        {
            m.push(get('C', fre));
        }
        if (x==3)
        {
            m.push(get('D', fre));
        }
        if (x==4)
        {
            m.push(get('E', fre));
        }
        
        if (x==5)
        {
            m.push(get('F', fre));
        }
     
        x++;
    }
    huff();
    for (int i = 0; i < 6; i++) 
    {
        enc(m.top(),"",i);
    }
    map<char, string>::iterator it = t.begin();
    while(it != t.end())
    {
        cout<<it->first<<":"<<it->second<<endl;
        it++;
    }
}