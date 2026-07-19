#include <iostream>
#include <vector>
#define ll long long int
using namespace std;


struct Edge{
    int src;
    int dest;
    int wt;
};

bool com( Edge e1 , Edge e2){
    return e1.wt < e2.wt;
}

int find( vector<int> &parent , int x){

    return parent[x]= parent[x] == x ? x : find( parent , parent[x]);
}

bool DSU( vector<int> & parent , vector<int> & rank , int x, int y){

    x = find ( parent , x);
    y = find( parent , y);

    if( x == y) return true;

    if( rank[x] > rank[y]){
        rank[x]++;
        parent[y] = x;

    }else{
        rank[y]++;
        parent[x ] = y;
    }

    return false;
}

ll kruskal( vector<Edge> & node , int n , int e){

    sort(node.begin() , node.end() , com);

    vector<int> parent(n + 1);
    vector<int> rank( n + 1 , 1);

    for( int i = 0; i <= n; i++){
        parent[i] = i;

    }

    int edge = 0;
    int i = 0; 
    ll ans = 0;

    while( edge < n - 1 && i < node.size()){

        Edge curr = node[i];

        int x = curr.src;
        int y = curr.dest;

        if( x != y){

            DSU( parent , rank , x , y);
            edge++;
            ans += curr.wt;

        }
       i++;

    }
 return ans;


}

int main(){
    int n ,e;
    cin>>n>>e;
    vector<Edge> node(e);

    for( int i = 0; i < e; i++){
        cin>>node[i].src>>node[i].dest>>node[i].wt;
    }

    cout<<kruskal( node , n , e)<<endl;
    return 0;
}

