#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int>adj[N];
bool vis1[N];
bool vis2[N];



void bfs(int source){
    queue<int>q;
    q.push(source);
    vis1[source] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto it: adj[node]){
            if(!vis1[it]){
                vis1[it] = 1;
                q.push(it);
            }
        }
    }
}


void dfs(int vertex){
    cout << vertex <<endl;
    vis2[vertex] = true;

    for(int child : adj[vertex]){
        if(vis2[child]) continue;

        dfs(child);
    }
}


int dis_connected_componet(int n){
    int count = 0;
    for(int i = 1; i<= n; i++){
        if(!vis2[i]){
            dfs(i);
            count++; 
        }
       
    }
    return count;
}



int main(){
    cout << "Enter number of vertices: ";
    int n; 
    cin >> n;
    cout << "Enter number of edges: ";
    int e; cin >> e;

    for(int i = 0; i< e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  

    int source;
    cin >> source;

    bfs(source);
    cout << endl;

    dfs(source);

    int c = dis_connected_componet(n);
    cout << c << endl;

    // input 1 se lena hai
}