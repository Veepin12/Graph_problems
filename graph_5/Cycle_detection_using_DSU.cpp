//
//  find_cycle_on_bi_dir_graph.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 17/07/26.
//

// There are some algo that used to find the cycle in the graph.
// 1. BFS.
// 2. DFS.
// 3. DSU ( Disjoint set Union).

// Time complexity = O(E + log(V)).

#include <iostream>

using namespace std;

int find(vector<int> & parent ,int x){
    return parent[x] = parent[x] == x ? x : find(parent,parent[x]);
}

bool Union( vector<int> & parent , vector<int> & rank , int x , int y){
    
    x = find( parent , x);
    y = find( parent , y);
    
    if( x == y) return true;
    
    if( rank[x] >= rank[y]){
        rank[x]++;
        parent[y] = x;
    }
    else {
        rank[y]++;
        parent[x] = y;
    }
    
    return false;
}

int  main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> parent(n + 1);
    vector<int> rank(n+ 1, 0);
    
    for( int i = 0; i <= n ; i++){
        parent[i] = i;
    }
    
    while( m --){
       
        
        
            int x,y;
            cin>>x>>y;
            bool ans = Union(parent , rank , x , y);
            if( ans == true) cout<<"cycle detected"<<"\n";
       
        
    }
    return 0;
}
