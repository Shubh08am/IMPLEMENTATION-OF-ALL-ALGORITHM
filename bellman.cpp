#include <bits/stdc++.h>
using namespace std; 

void bellman(int V,vector<vector<int>>&edge,int s){
     vector<int>dist(V,(int)1e9) ; 
     dist[s]=0;
     for(int i=0;i<V-1;i++){
        for(auto it : edge){
                int u=it[0] , v=it[1] , w = it[2] ; 
                //relaxation 
                //if possible to reach v from u than only 

                if(dist[u]!= 1e9 && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
        }

                //check negative cycle 
                for(auto it : edge){
                 int u=it[0] , v=it[1] , w = it[2] ; 
 
                if(dist[u]!= 1e9 && dist[u] + w < dist[v]){
                    cout<<"negative-present\n";
                }
                }
        }
 

 for(auto i : dist) cout<<i<<" ";
}
 
int main(){   

int n , e ; 
cin>>n>>e; 
vector<vector<int>>edge;

for(int i=0;i<e;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edge.push_back({u,v,w}) ; 
}
 
    int s; 
    cin>>s; 
          
    bellman(n,edge,s) ; 
    
return 0 ;
}
 
