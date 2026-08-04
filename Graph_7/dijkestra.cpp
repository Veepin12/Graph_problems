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
#include <climits>

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
        pq.pop();
        
        int node = curr.second;
        
        if( vis.count(node)){
            continue;
        }
        
        vis.insert(node);
        
        for ( auto neighbour : graph[node]){
            int nbr = neighbour.first;
            int wt = neighbour.second;
            if( !vis.count(nbr) && mp[nbr] > mp[node] + wt){
                mp[nbr] = mp[node] + wt;
                via[nbr] = node;
                pq.push({mp[nbr] , nbr});
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
