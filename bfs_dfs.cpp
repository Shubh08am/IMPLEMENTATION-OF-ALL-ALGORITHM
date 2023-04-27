#include <bits/stdc++.h>
using namespace std; 

void bfs(int V,vector<int>adj[]){
    queue<int>q;
    vector<int>vis(V,0) ; 
    vis[0]=1;
    q.push(0);
        
    while(!q.empty()){
        int node = q.front() ; 
        q.pop();
        cout<<node<<" ";
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }

}

void dfs(int node,vector<int>adj[],vector<int>&vis){
vis[node]=1; 
cout<<node<<" "; 

for(auto it : adj[node]){
    if(!vis[it]){
        dfs(it,adj,vis);
    }
}

}


int main(){   

int n , edge ; 
cin>>n>>edge; 
vector<int>adj[n] ; 

for(int i=0;i<edge;i++){
    int u,v;
    cin>>u>>v; 
    adj[u].push_back(v) ; 
}

 // bfs(n,adj);
   
   vector<int>vis(n,0) ; 
   dfs(0,adj,vis) ; 

return 0 ;
}
