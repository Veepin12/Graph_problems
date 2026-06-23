#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<unordered_set<int>> graph;
int v;

void add_edge( int src , int dist  , bool bi_dir = true){
    graph[src].insert(dist);
    if ( bi_dir){
        graph[dist].insert(src);
    }

}

void display(){
    for( int i = 0; i < graph.size(); i++){
        cout<<i<<"->";
        for( auto el : graph[i]){
            cout<<"("<<el<<")";
        }
        cout<<"\n";
    }
}
int main(){
    cin >>v;

    graph.resize( v , unordered_set<int> ());

    int edge;
    cin>>edge;

    while( edge --){
        int src, dist;
        cin>>src>>dist;
        add_edge( src , dist);
    }
    display();
    return 0;
}
