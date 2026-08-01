//
//  Dijsketra.cpp
//  DSA_with_Cpp
//

#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <vector>
#include <climits> // Fixed: Required for INT_MAX

#define ll long long int
#define pp pair<int , int >
using namespace std;

int v;
vector<list<pair<int,int>>> graph;

void add_edge(int src, int dest, int wt, bool bi_dir = true) {
    graph[src].push_back({dest, wt});
    if (bi_dir) {
        graph[dest].push_back({src, wt});
    }
}

unordered_map<int, int> dijkestr(int src, int n) {
    // pair<int, int> stores {accumulated_distance, node}
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    
    unordered_map<int, int> mp;
    vector<int> via(n + 1);
    
    for (int i = 0; i < n; i++) {
        mp[i] = INT_MAX;
    }
    
    pq.push({0, src});
    mp[src] = 0;
    
    while (!pq.empty()) {
        pp curr = pq.top();
        pq.pop(); // Fixed: Popping here cleanly
        
        int curr_node = curr.second;
        
        if (vis.count(curr_node)) {
            continue;
        }
        
        vis.insert(curr_node);
        
        for (auto neighbour : graph[curr_node]) {
            int nbr_node = neighbour.first;
            int edge_wt = neighbour.second;
            
            // Relaxation condition:
            // Check if the total new distance is shorter than the currently recorded distance
            if (!vis.count(nbr_node) && mp[nbr_node] > mp[curr_node] + edge_wt) {
                mp[nbr_node] = mp[curr_node] + edge_wt; // Fixed: Update total distance
                via[nbr_node] = curr_node;               // Fixed: Track predecessor node
                pq.push({mp[nbr_node], nbr_node});        // Fixed: Push {total_dist, node}
            }
        }
    }
    
    return mp;
}

int main() {
    cin >> v;
    
    graph.resize(v, list<pair<int, int>>());
    
    int edge;
    cin >> edge;
    
    while (edge--) {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        add_edge(src, dest, wt);
    }
    
    int src;
    cout << "Enter the Source Node :";
    cin >> src;
    
    unordered_map<int, int> sp = dijkestr(src, v);
    cout << "\n";
    for (auto el : sp) {
        cout << el.first << " -> " << (el.second == INT_MAX ? -1 : el.second) << "\n";
    }
    
    int dest;
    cout << "Enter the Destination Node :";
    cin >> dest;
    
    if (sp[dest] == INT_MAX) {
        cout << "Unreachable\n";
    } else {
        cout << "Shortest Distance: " << sp[dest] << "\n";
    }
    
    return 0;
}
