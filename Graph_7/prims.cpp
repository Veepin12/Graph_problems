//
//  Prims.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 20/07/26.
//

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#define ll long long int

using namespace std;

// this algo contain greedy and BFS with priority Queue Data structure..

vector<list<pair<int , int>>> graph;
void add_edge( int src , int dest , int wt , bool bi_dir = true){
    graph[src].push_back({dest , wt});
    if( bi_dir){
        graph[dest].push_back( { src, wt});
    }
}
class Solution{
public:
    
    ll prims(int source, int n){
        unordered_map<int, int> mp;
        unordered_set<int> visited;
        priority_queue<pair<int , int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        vector<int> parent( n + 1);
        for( int i = 1; i <= n; i++){
            mp[i] = INT_MAX;
        }
        pq.push({ 0 , source});
        mp[source] = 0;
        
        int total_vertices = 0;
        ll ans = 0;
        
        while ( total_vertices < n && !pq.empty()){
            
            auto curr = pq.top();
            
            if(visited.count(curr.second)) {
                pq.pop();
                continue;
            }
            int child = curr.first;
            int child_wt = curr.second;
            visited.insert(child_wt);
            total_vertices++;
            ans += child;
            
            pq.pop();
            
            for( auto neighbour : graph[curr.second]){
                if( !visited.count(neighbour.first) && mp[neighbour.first] > neighbour.second){
                    pq.push({neighbour.second , neighbour.first});
                    mp[neighbour.first] = neighbour.second;
                }
            }
            
            
        }
        return ans;
    }
    
};


int main(){
    int n;
    cin>>n;
    
    graph.resize( n + 1, list<pair<int , int>> ());
    
    int e;
    cin>>e;
    
    while( e--){
        int src , dest , wt;
        cin>>src>>dest>>wt;
        add_edge( src , dest , wt, false);
    }
    int source ;
    cin>>source;
    Solution S;
    
    cout<<S.prims(source , n)<<endl;
    
    return 0;
    
}
