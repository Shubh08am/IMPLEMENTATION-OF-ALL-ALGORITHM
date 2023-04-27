#include <bits/stdc++.h>
using namespace std; 

void dijkstra(int V,vector<vector<int>>adj[],int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(V,(int)1e9) ; 
    dist[s]=0;
    pq.push({0,s});
        
    while(!pq.empty()){
        int node = pq.top().second , dis = pq.top().first; 
        pq.pop();
         for(auto it : adj[node]){
            int adjNode = it[0] ; 
            int edgeWt = it[1] ; 

            if(dis+edgeWt < dist[adjNode]) {
                dist[adjNode] = dis+edgeWt  ; 
                pq.push({dis+edgeWt ,adjNode}) ; 
            }
    }
    
}
for(auto i : dist) cout<<i<<" ";
}
 
int main(){   

int n , edge ; 
cin>>n>>edge; 
vector<vector<int>>adj[n] ; 

for(int i=0;i<edge;i++){
    int u,v,w;
    cin>>u>>v>>w;
    vector<int>a,b; 
    a.push_back(v); a.push_back(w) ; 
    b.push_back(u); b.push_back(w) ;
    adj[u].push_back(a) ; 
    adj[v].push_back(b) ; 
}
 
    int s; 
    cin>>s; 
          
    dijkstra(n,adj,s) ; 
    
return 0 ;
}
 
