#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

vector<list<int>> graph;
int v; // vertex.

void add_edge( int src , int dest , bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }

}
unordered_set<int> visited;
vector<vector<int>> res;



void BFS( int src , vector<int> & dist){
    queue<int> qu;
    visited.clear();
    dist.resize(v , INT_MAX);
    dist[src] = 0;
    visited.insert(src);

    qu.push(src);
    while( !qu.empty()){
        int curr = qu.front();
        qu.pop();
        for( auto el : graph[curr]){
            if(!visited.count(el)){
                qu.push(el);
                visited.insert(el);
                dist[el] = dist[curr] + 1;
            }
        }
    }
}


int main(){
    cin>>v;
    graph.resize(v , list<int> ());

    int e ; // Edge.
    cin>>e;

    while(e--){
        int src ,dist;
        cin>>src>>dist;

        add_edge(src , dist);
    }
    int n;
    cin>>n;
    vector<int> dist;
    BFS( n , dist);

    for( int i= 0; i < dist.size();i++){
        cout<<dist[i]<< ",";
    }
    return 0;
}