//Lab 12: by Andrew Le Nguyen
/*#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <stack>
#define infinity 9999
using namespace std;
bool visit[infinity];
int j=1;
void DFS(int n, list<int>adj[], int arr[], int num){
    j++;
    list<int>::iterator it;
    for(it = adj[n].begin();it!=adj[n].end();it++){
        if (!visit[*it]){
            visit[*it]=true;
            DFS(*it,adj,arr,num);
        }
        if(visit[*it]){
            j++;
        }
    }
    arr[n]=j;
}
void hashsearch(list<int>T[], int k,int num,bool found[]){
    list <int> :: iterator it;
    for(int p =0; p<num;p++){
        for(it = T[p].begin(); it != T[p].end(); ++it){
            if(*it==k){
                cout<<p<<endl;
                found[k]=true;
                break;
            }
     
        }
       
    }
}
void dfs2(int n, list<int>t[], list<int>Final[], int in){
    list<int>::iterator it;
    for(it = t[n].begin();it!=t[n].end();it++){
        if (!visit[*it]){
            Final[in].push_back(n);
            visit[*it]=true;
            dfs2(*it,t,Final,in);
        }
    }
}
void insert(int vericies, int edge, list<int>adj[]){
    adj[edge].push_back(vericies);
}
void printtable(int num, list<int>adj[]){
    list <int> :: iterator it;
    for(int i = 0; i<num;i++){
        cout<<i<<":";
        for(it = adj[i].begin(); it != adj[i].end(); ++it){
            cout<<*it<<"->";
        }
        cout<<";"<<endl;
    }
}
void trans(list<int>T[],list<int>adj[],int num ){
    list <int> :: iterator it;
    for(int i = 0; i<num;i++){
        for(it = adj[i].begin(); it != adj[i].end(); ++it){
             T[*it].push_back(i);
        }
    }
}
void Scc(list<int>T[],int nums, int arr[],list<int>Final[]){
    for(int i =0; i<nums;i++){
        if(!visit[i]){
            dfs2(arr[i], T, Final,arr[i]);
        }
        if(T[i].empty()){
            Final[i].push_back(i);  
        }
    }
}
void order(int arr[], int num, int order[]){
    int o =0;
    for (int i =0; i <num;i++){
        o =distance(arr, max_element(arr, arr + num));
        order[i]=o;
        arr[o]=0;
    }
}
int main(int argc, const char * argv[]) {
    int loop=0;
    int num;
    cin>>num;
    int arr[num];
    int S[num];
    list<int>adj[num];
    list<int>t[num];
    list<int>Final[num];
    cin>>loop;
    int verticies;
    int edges;
    for(int l=0; l<loop;l++){
    cin>> verticies>>edges;
        insert(edges, verticies, adj);
    }
    trans(t,adj,num);
    DFS(0,adj,arr,num);
    for (int v=0;v<num;v++){
        if(!visit[v]){
            arr[v]=j+2;
        }
        visit[v]=NULL;
    }
    order(arr,num,S);
    Scc(t, num, S, Final);
    for (int v=0;v<num;v++){
        if(!visit[v]){
           Final[v].push_back(v);
        }
    }
    bool found[num];
    for(int p=0;p<num;p++){
        hashsearch(Final, p, num,found);
    }
}*/

#include <iostream>

using namespace std;
// a structure to represent a weighted edge in graph
struct Edge
{
int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph
{
// V-> Number of vertices, E-> Number of edges
int V, E;

// graph is represented as an array of edges.
struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
struct Graph* graph = new Graph;
graph->V = V;
graph->E = E;
graph->edge = new Edge[E];
return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n)
{
for (int i = 0; i < n; ++i) {
if(dist[i] == 2147483647)
printf("INFINITY\n");
else
printf("%d\n", dist[i]);
}
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm. The function
// also detects negative weight cycle
void BellmanFord(struct Graph* graph, int src)
{
int V = graph->V;
int E = graph->E;
int dist[V];

// Step 1: Initialize distances from src to all other vertices
// as INFINITE
for (int i = 0; i < V; i++)
dist[i] = 2147483647;
dist[src] = 0;

// Step 2: Relax all edges |V| - 1 times. A simple shortest
// path from src to any other vertex can have at-most |V| - 1
// edges
for (int i = 1; i <= V-1; i++)
{
for (int j = 0; j < E; j++)
{
int u = graph->edge[j].src;
int v = graph->edge[j].dest;
int weight = graph->edge[j].weight;
if (dist[u] != 2147483647 && dist[u] + weight < dist[v])
dist[v] = dist[u] + weight;
}
}

// Step 3: check for negative-weight cycles. The above step
// guarantees shortest distances if graph doesn't contain
// negative weight cycle. If we get a shorter path, then there
// is a cycle.
for (int i = 0; i < E; i++)
{
int u = graph->edge[i].src;
int v = graph->edge[i].dest;
int weight = graph->edge[i].weight;
if (dist[u] != 2147483647 && dist[u] + weight < dist[v]) {
cout << "FALSE";
return;
}
  
}
cout << "TRUE\n";
printArr(dist, V);
}

// Driver program to test above functions
int main()
{
/* Let us create the graph given in above example */
int V; // Number of vertices in graph
int E; // Number of edges in graph
  
cin >> V >> E;
  
int u, v, c;
struct Graph* graph = createGraph(V, E);

for(int i=0; i<E; i++) {
cin >> u >> v >> c;
graph->edge[i].src = u;
graph->edge[i].dest = v;
graph->edge[i].weight = c;
}
  
BellmanFord(graph, 0);
return 0;
}