#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];

void DFS(int source, stack<int>&st, vector<int>adj[])
{
    vis[source] = true;
    for (int child : adj[source])
    {
        if (!vis[child])
            DFS(child,st,adj);
    }
    st.push(source);
}

void toposort(vector<int> adj[], int V)
{
    stack<int>st;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            DFS(i,st,adj) ;
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];
    while (E--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    toposort(adj,V);

    // input 0 index se lena hai
}