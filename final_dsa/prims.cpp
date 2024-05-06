#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<pair<int, int>> adj[N];

int main() {
    cout << "Enter number of vertices:";
    int v;
    cin >> v;
    cout << "Enter number of edges:";
    int e;
    cin >> e;

    for (int i = 0; i < e; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
        adj[y].push_back({x, wt});
    }

    int key[v + 1];
    bool mstSet[v + 1];

    for (int i = 0; i <= v; i++) {
        key[i] = INT_MAX; 
        mstSet[i] = false; 
    }

    key[1] = 0;
    int ansWeight = 0;

    for (int i = 1; i < v; i++) {
        int mn = INT_MAX, u = -1;

        for (int j = 1; j <= v; j++) {
            if (mstSet[j] == false && key[j] < mn) {
                mn = key[j], u = j;
            }
        }

        mstSet[u] = true;
        for (auto it : adj[u]) {
            int ver = it.first;
            int weight = it.second;
            if (mstSet[ver] == false && weight < key[ver]) { 
                key[ver] = weight; 
            }
        }
        
    }

    for (int i = 1; i <= v; i++) {
        ansWeight += key[i];
    }

    for (int i = 1; i <= v; i++) {
        cout << key[i];
    }
    
    cout << endl;
    cout << "MINIMUM SUM : " << ansWeight << endl;

    return 0;
}