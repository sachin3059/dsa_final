#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 +10;


int parent[N];
int Size[N];


void make(int v){
    parent[v] = v;
    Size[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}


void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[a] < Size[b]){
            swap(a, b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}


int main(){
    int v, e;
    cin >> v >> e;
    
    vector<pair<int, pair<int, int> > > edges;
    for(int i = 0; i< e; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        edges.push_back({wt, {x, y}});
    }

    sort(edges.begin(), edges.end());

   

    for(int i = 1; i<= v; i++){
        make(i);
    }

    int total_cost = 0;
    for(auto &edge : edges){
        int wt = edge.first;
        int x = edge.second.first;
        int y = edge.second.second;

        if(find(x) == find(y)) continue;
        Union(x, y);
        total_cost += wt;

        cout << "edges: " << endl;
        cout << x << " " <<  y << endl;
    }
    cout <<"total_cost : " <<  total_cost << endl;
}