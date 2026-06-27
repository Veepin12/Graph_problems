#include <iostream>
#include <unordered_set>
using namespace std;


class Node{
public:
    int val;
    vector<Node*> neighbour;

    Node( ){
        val = 0;
        neighbour = vector<Node*>();
    }
    Node( int val){
        val = val;
        neighbour = neighbour;
    }
    Node( int val , vector<Node * > neighbour){
        val = val;
        neighbour = neighbour;
    }
};

class Solution{
public:

    Node* cloneGraph( Node * node){

        Node * temp = new Node();

        stack<Node*> st;
        unordered_set<Node *> visited;
        st.push(temp);

        visited.insert(temp);

        while( ! st.empty()){
            Node * curr = st.top();
            st.pop();
            visited.insert(curr);

            for( auto neighbour : * node.(curr)){
                if( visited.count(neighbour)){
                    st.push(neighbour);
                    visited.insert(neighbour);

                }
            }
        }
        return 

    }
};
int main(){
    return 0;
}