#include<bits/stdc++.h>
using namespace std;

int prims(int V , vector<vector<int>>adj[]){

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
pq.push({0,0}) ; 
vector<int>vis(V,0); 

int mst=0;
while(!pq.empty()){
    int node = pq.top().second , wt = pq.top().first; 
    pq.pop();

    if(!vis[node]){
       vis[node]=1;
       mst+=wt; 

    for(auto it : adj[node]){
        int adjNode = it[0] ; 
        int  edgeWt = it[1] ; 

        if(!vis[adjNode]){
            pq.push({edgeWt,adjNode}) ; 
        }
    }
    }
}
return mst;
}

int main(){
    int n,edge;
    cin>>n>>edge;

    vector<vector<int>>adj[n];

    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<< prims(n,adj) ; 
    return 0;
}
