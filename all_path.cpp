#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
#include <algorithm>


using namespace std;

vector<list<int>> graph;
int v;
unordered_set<int> visited;
vector<vector<int>> result;
vector<int> path;

void add_edge( int src , int dist , bool bi_dir = true){
    graph[src].push_back(dist);
    if( bi_dir){
        graph[dist].push_back(src);
    }


}



void dfs( int curr , int end , vector<int> path ){
    if (curr == end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);// marked visited.
    path.push_back( curr); 
    
    for( auto neighbour : graph[curr]){
        if(!visited.count(neighbour)){
            dfs(neighbour , end , path);
        }

    }
    path.pop_back();
    visited.erase(curr);
    return;


}

int main(){
    cin>>v;
    graph.resize(v, list<int> ());

    int e;
    cin>>e;

    while( e--){
        int src,dist ;
        cin>>src>>dist;

        add_edge(src , dist);
    }
    int curr , end;
    cin>>curr>>end;
    dfs( curr , end ,path);


    cout<<"(";
    for( auto path : result ){
        cout<<"(";
        for( auto ele : path){
            cout<<ele<<",";
        }
        cout<<")";
    }
    cout<<")";
    cout<<endl;


    return 0;
}