#include<bits/stdc++.h>
using namespace std;

void toposort(int v, vector<int>adj[]){
    int indegree[v] = {0};
    for(int i = 0; i< v; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i = 0; i< v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }

    }
}


int main(){
    cout << "Enter number of vertices: ";
    int v; cin >> v;
    cout << "Enter number of edges: ";
    int e; cin >> e;
    
    vector<int>adj[v];
    for(int i = 0; i< e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    toposort(v, adj);
}