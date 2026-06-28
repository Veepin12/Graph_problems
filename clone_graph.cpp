#include <iostream>
#include <unordered_set>
using namespace std;


class Node{
public:
    int val;
    vector<Node*> neighbors;

    Node( ){
        val = 0;
        neighbors = vector<Node*>();
    }
    Node( int val){
        val = val;
        neighbors = neighbors;
    }
    Node( int val , vector<Node * > neighbors){
        val = val;
        neighbors = neighbors;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (visited.count(node)) {
            return visited[node];   // already cloned -> avoid infinite loop
        }

        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;          // map BEFORE recursing (critical for cycles)

        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};
int main(){
    
    return 0;
}