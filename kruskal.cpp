#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) 
            parent[i] = i;
    }
    int findParent(int node) {
        return (node==parent[node]) ? node : parent[node] = findParent(parent[node]);
    }
    void unite(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if(up != vp) {
            if(rank[up] < rank[vp])
                parent[up] = vp;
            else if(rank[up] > rank[vp]) 
                parent[vp] = up;
            else {
                parent[up] = vp;
                rank[vp]++;
            }
        }
    }
};

int kruskal(vector<vector<int>> adj[], int V) {
    vector<vector<int>> graph;
    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) {
            int node = i, adjNode = it[0], w = it[1];
            vector<int> temp = {w, node, adjNode};
            graph.push_back(temp);
        }
    }
    int cost = 0;
    sort(begin(graph),end(graph)); //greedy 
    DisjointSet ds(V);
    for(auto edge : graph) {
        int w = edge[0], u = edge[1], v = edge[2];
        if(ds.findParent(u) != ds.findParent(v)) {
            ds.unite(u, v);
            cost += w;
        }
    }
    return cost;
}

int main(){
    int n; cin>>n;
    int edge; cin>>edge;
    vector<vector<int>> adj[n];
    for(int i = 0; i < edge; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[u].push_back({v, w});
    }
    cout << kruskal(adj, n);
    return 0;
}
