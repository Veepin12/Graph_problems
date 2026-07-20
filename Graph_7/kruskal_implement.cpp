#include <iostream>
#include <list>
#define ll long long int

using namespace std;





class Solution{
public:

    int find( vector<int> & parent , int x){

        return parent[x] = parent[x] == x ? x : find( parent , parent[x]);

    }
    bool DSU( vector<int> & parent , vector<int> &  rank , int x , int  y){

        x = find( parent , x);
        y = find( parent , y);

        if( x == y) return true;

        if( rank[x] > rank[y]){
            rank[x]++;
            parent[y] = x;

        }
        else{
            rank[y]++;
            parent[x] = y;
        }

        return false;
    }

    ll kruskal( int n , vector<vector<int>> & nums){

        sort(nums.begin() , nums.end() , []( vector<int> & a , vector<int> & b) { return a[2] < b[2];});

        vector<int> parent( n + 1 );
        vector<int> rank( n + 1, 1);

        for( int i = 0; i <= n; i++ ){
            parent[i] = i;
        }

        int edgeCount = 0;
        int i = 0;
        ll ans = 0;

        while( edgeCount < n - 1  && i < nums.size()){

            auto curr = nums[edgeCount];

            int src = curr[0];

            int dest = curr[1];

            if( src != dest){

                DSU( parent , rank , src , dest );
                edgeCount++;
                ans += curr[2];

            
            }
            i++;
        }

    return ans;
    }

};

int main(){

    int n,e;
    cin>>n>>e;

  
    vector<vector<int>> nums(e , vector<int> ( 3));
    for( int i = 0; i < e ; i++){
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    }
    Solution S;
    cout<<S.kruskal( n , nums)<<endl;

    return 0;
}