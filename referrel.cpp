#include <iostream>
#include <list>
using namespace std;

vector<list<int>> graph;
int v; // vertex of graph.


void add_edge( int src , int dest , bool bi_dir = true){
    graph[src].push_back(dest);
    if( bi_dir){
        graph[dest].push_back(src);
    }
}

void display(){

    for(int i = 0; i < graph.size(); i++){ 
        cout<<i <<"->";
        for( int j : graph[i]){
            cout << j <<"->";
        }
        cout<<endl;

    }

}


int main(){
    cin>>v;
    graph.resize( v, list<int> ());

    // egde;
    int e;

    cin>>e;
    while( e--){
        int src , dest;
        cin>>src>>dest;
        add_edge( src , dest);
    }
    display();
    return 0;

}