//
//  Dijsketra.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 20/07/26.
//

#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <vector>
#define ll long long int
#define pp pair<int , int >
using namespace std;

int v;
vector<list<pair<int,int>>> graph;

void add_edge( int src , int dest , int wt , bool bi_dir = true){
    graph[src].push_back({dest , wt});
    if(bi_dir){
        graph[dest].push_back({src , wt});
    }
}

unordered_map< int , int> dijkestr( int src , int n){
    
    priority_queue<pp , vector<pp> , greater<pp>> pq;
    unordered_set<int> vis;
    
    unordered_map< int , int> mp;
    vector<int> via( n + 1);
    
    for( int i = 0 ; i < n; i++){
        mp[i] = INT_MAX;
    }
    
    
    pq.push({ 0 , src});
    mp[src] = 0;
   
   
    
    while( !pq.empty()){
        pp curr = pq.top();
        if( vis.count( curr.second)){
            pq.pop();
            continue;
        }
        
        vis.insert(curr.second);
       
        pq.pop();
        
        for ( auto neighbour : graph[curr.second]){
            if( !vis.count(neighbour.first) && mp[neighbour.first] > mp[curr.second] + neighbour.second){
                pq.push({neighbour.second , neighbour.first});
                via[neighbour.first] = neighbour.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    
    
    
    return mp;
    
}




int main(){
    cin>>v;
    
    graph.resize( v , list<pair<int, int>> ());
    
    int edge;
    cin>>edge;
    
    while( edge--){
        int src , dest , wt ;
        cin>>src>>dest>>wt;
        add_edge( src , dest , wt);
        
    }
    int src;
    cin>>src;
    
    unordered_map< int , int> sp = dijkestr(src, v);
    
    for( auto el : sp){
        cout<<el.first<< "" <<el.second<<"\n";
    }
    
    int dest ;
    cin>>dest;
    
    
    cout<<sp[dest]<<"\n";
    
    
    return 0;
}
