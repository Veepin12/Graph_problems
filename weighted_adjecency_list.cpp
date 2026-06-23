#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// in this Approch we implemented the graph as a array of liknked list. 

vector<list<pair<int , int>>> graph;
int v;
void add_edge(int src , int dist ,int wt , bool bi_dir = true){
    graph[src].push_back ({dist, wt});
    if( bi_dir ){
        graph[dist].push_back({src, wt});
    }
}

void display(){
    for( int i = 0 ; i < graph.size(); i++){
        cout<<i<<" -> ";
        for( auto & el: graph[i]){
            cout<< "(" <<el.first <<"," <<el.second<<")";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>v;
    graph.resize(v,list<pair<int, int>> ());
    int e;
    cin>>e;
    while( e--){
        int src,dist ,wt;
        cin>>src>>dist>>wt;
       
       
        add_edge(src , dist , wt);

    }
    display();
    
    return 0;

}