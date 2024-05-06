#include<bits/stdc++.h>
using namespace std;
const int M = 1e5 +1;
const int N = 1e5 +10;

vector<pair<int, int>> adj[N];
vector<int>dist(N, M);

void dijkstra(int source, int dest,  int n){
    set<pair<int,int>>st;          
    st.insert({0,source});
    dist[source] = 0;

    vector<int>parent(n+1);
    for(int i = 0; i<= n; i++){
        parent[i] = i;
    }


    while(st.size() > 0){
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

    
        for(auto child : adj[v]){
            int child_v = child.first;
            int wt = child.second;

            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
                parent[child_v] = v;
            }
        }
    }

    vector<int> path;
    int node = dest;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());


    if(dist[dest] != M){
        cout << "Total_distance : " << dist[dest] << endl;
        cout << "Shortest path : " ;
        for(auto it: path){
            cout << it <<" ";
        }
    }
    else{
        cout << "Path no exist" << endl;
    }
}

int main(){
    cout << "Number of vertices: ";
    int v; cin >> v;
    cout << "Number of edges: ";
    int e; cin >> e;

    for(int i = 0; i< e; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
    }

    cout << "Enter source: ";
    int s; cin >> s;

    cout << "Enter destination: ";
    int dest; cin >> dest;

    dijkstra(s, dest, v);

}