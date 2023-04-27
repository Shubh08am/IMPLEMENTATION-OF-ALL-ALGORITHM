#include <bits/stdc++.h>
using namespace std; 

void floyd(vector<vector<int>>&mat){
    int n = mat.size() ;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(mat[i][j]==-1) {
            mat[i][j] = (int)1e8 ; 
        }
        if(i==j) mat[i][j] = 0 ; 
    }
}
 
 for(int k=0;k<n;k++){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=min(mat[i][j] , mat[i][k]+mat[k][j]) ; 
      }
}
}

//negative cycle 
for(int i=0;i<n;i++){
    if(mat[i][i]<0) {
        cout<<"present\n" ;
    }
}

//1e8 valo ko -1 kro 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(mat[i][j]==1e8) {
                mat[i][j]=-1;
        }}

}
}


int main(){   

int n  ; 
cin>>n; 

vector<vector<int>>mat(n,vector<int>(n,-1)) ;

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>mat[i][j];
    }
}
 
 floyd(mat) ; 
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
}
 
 
   
return 0 ;
}
 
