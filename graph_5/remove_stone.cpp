#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


// this question based on leetcode 947.

// Recursion based question.
    
vector<list<int>> graph;
int v;
    
    
    


void add_edge( int src, int dest ,bool bi_dir= true ){
   
    
    graph[src].push_back({dest} );
    
    
    if(bi_dir){
        graph[dest].push_back({src});
       
    }
   
        
}
    
void dfs( int node , unordered_set<int>& visited){
        visited.insert(node);
        for(auto neighbour : graph[node]){
            if( !visited.count(neighbour)){
                dfs( neighbour , visited);
            }
        }
        
}
int connected_component(){
        int res = 0;
        unordered_set<int> visited;
        
        for( int i = 0; i < v; i++){
            if( visited.count(i) == 0){
                res++;
                dfs( i , visited);
            }
            
        }
        return res;
}

int remove(int n){
    
    int cc = connected_component();
    
    
    return  abs(n - cc );
    
}
    

int main(){
    cin>>v;
    graph.resize( v , list<int> ());
    int e;
    cin>>e;
    int a = e;
    while( e--){
        int src , dest;
        cin>>src>>dest;
        add_edge( src , dest);


    }

    cout<<"Connected Component : "<<connected_component()<<endl;
    
    cout<<"Remove Stone is : "<<remove(a)<<endl;

    return 0;
}
