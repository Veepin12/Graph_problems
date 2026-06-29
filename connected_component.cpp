#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

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
void display(){
    for( int i = 0 ; i < graph.size(); i++){
        cout<<i<<" -> ";
        for( auto & el: graph[i]){
            cout<< el;
        }
        cout<<"\n";
    }
}

int main(){
    cin>>v;
    graph.resize( v , list<int> ());
    int e;
    cin>>e;
    while( e--){
        int src , dest;
        cin>>src>>dest;
        add_edge( src , dest);


    }
    display();
    cout<<connected_component();

    return 0;
}