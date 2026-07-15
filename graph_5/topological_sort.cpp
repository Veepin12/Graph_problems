//
//  Kann's_algorithm.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 15/07/26.
//

#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int src, int dest) {
    graph[src].push_back(dest);
}

void TOPS() {
    // Kahn's algorithm works on a directed acyclic graph.
    vector<int> indegree(v, 0);

    for (int i = 0; i < v; i++) {
        for (int neighbour : graph[i]) {
            indegree[neighbour]++;
        }
    }

    queue<int> qu;

    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            qu.push(i);
        }
    }

    vector<int> order;
    while (!qu.empty()) {
        int node = qu.front();
        qu.pop();
        order.push_back(node);

        for (int neighbour : graph[node]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                qu.push(neighbour);
            }
        }
    }

    if (static_cast<int>(order.size()) != v) {
        cout << "Topological sort is not possible: the graph contains a cycle.\n";
        return;
    }

    for (int node : order) {
        cout << node << ' ';
    }
    cout << '\n';
}



int main(){
    cin>>v;
    graph.resize(v, list<int> ());
    
    int e;
    cin>>e;
    
    while( e--){
        int s , dest ;
        cin>>s>>dest;
        add_edge( s , dest );
        
    }
    TOPS();
    return 0;
}
