// Lab 06: by Andrew Le Nguyen
// With help from David Nguyen

#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;
void hinsert(list<int>* h, int k, int s)
{
	int pos = (k % s);
	h[pos].push_front(k);
}

void hsearch(list<int>* h, int k, int s)
{
	int pos = (k % s);
	int count = 0;
	bool bl = false;
	list<int>::iterator ch;
	for(ch = h[pos].begin(); ch != h[pos].end(); ch++)
	{
		if(*ch == k)
		{
			cout << k << ":FOUND_AT" << pos << "," << count << ";" << endl;
			bl = true;
			break;
		}
		count++;
	}
	if(!bl)
	{
		cout << k << ":NOT_FOUND;" << endl;
	}
}

bool hdelete(list<int>* h, int k, int s)
{
	int pos = (k % s);
	int count = 0;
	bool bl = false;
	list<int>::iterator ch;
	for(ch = h[pos].begin(); ch != h[pos].end(); ch++)
	{
		if(*ch == k)
		{
			list<int>::iterator del = h[pos].begin();
			advance(del, count);
			h[pos].erase(del); 
			cout << k << ":DELETED;" << endl;
			return true;
		}
		count++;
	}
	if(!bl)
	{
		cout << k << ":DELETE_FAILED;" << endl;
	}
}
void print(list<int>* h, int s)
{
	list<int>::iterator ch;
	for(int i = 0; i < s; i++)
	{
		cout << i << ":";
		for(ch = h[i].begin(); ch != h[i].end(); ch++)
		{
			cout << *ch << "->";
		}
		cout << ";" << endl;
	}		
}

int main(){
	int s;
	cin >> s;
	list<int>* h = new list<int>[s];
	int k;
	string in;
	cin >> in;
	if(in[0] == 'e')
	{
		return 0;
	}
	while(in[0] != 'e')
	{
		if(in[0] == 'i')
		{
			k = stoi(in.substr(1));
			hinsert(h, k, s);	
		}
		if(in[0] == 'd')
		{
			k = stoi(in.substr(1));
			hdelete(h, k, s);
			
		}
		if(in[0] == 's')
		{
			k = stoi(in.substr(1));
			hsearch(h, k, s);
			
		}
		if(in[0] == 'o')
		{
			print(h, s);
		}
		cin >> in;
	}
	return 0;
}