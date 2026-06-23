#include <iostream>
#include<vector>
#include <unordered_set>
#include <list>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge( int src , int dist , bool bi_dir = true){
    graph[src].push_back(dist);
    if( bi_dir ){
        graph[dist].push_back(src);
    }

}
unordered_set<int> visited;
bool dfs( int curr , int end){
    if( curr == end) return true;
    visited.insert(curr);
    for( auto neighbour : graph[curr]){
        if(!visited.count(neighbour)){
            bool res = dfs( neighbour , end);
            if(res) return true;
        }
        
    }
    return false;

}

int main(){
    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    visited.clear();
    
   
    while( e --){
        int src ,dist ;
        cin>>src>> dist;
        add_edge(src , dist);


    }
    int n , m;
    cin>>n>>m;

    cout<<dfs(n , m);
}
