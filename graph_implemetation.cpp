#include <iostream>
using namespace std;

class node{
public:
    int data;

};
class edge{
public:
    node src;
    node data;
    int wt;
    bool dir = true; // Toword the direction of source to destination.
};

class graph{
public:

    vector<node> vertices;
    vector<edge> Edge;
};


int main(){
    return 0;
    
}