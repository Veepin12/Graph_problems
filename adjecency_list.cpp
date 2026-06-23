#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// in this Approch we implemented the graph as a array of liknked list. 

vector<list<int>> graph;
int v;
void add_edge(int src , int dist , bool bi_dir = true){
    graph[src].push_back (dist);
    if( bi_dir ){
        graph[dist].push_back(src);
    }
}

void display(){
    for( int i = 0 ; i < graph.size(); i++){
        cout<<i<<" -> ";
        for( auto el : graph[i]){
            cout<<el <<",";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while( e--){
        int src,dist;
        cin>>src>>dist;
       
       
        add_edge(src , dist);

    }
    display();
    
    return 0;

}