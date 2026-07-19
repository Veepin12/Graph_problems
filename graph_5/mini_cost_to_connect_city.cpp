#include <iostream>
using namespace std;



class Solution{
    public:

    int find( vector<int> & parent , int x){

        return parent[x] = parent[x] == x ? x :find( parent , parent[x]);
    }

    bool DSU( vector<int> & parent , vector<int> & rank , int x , int y){

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

    int mini_Cost( int n , vector<vector<int>> & nums){

        sort(nums.begin() , nums.end() , []( vector<int> & a , vector<int> & b){ return a[2] <  b[2];});

        vector<int> parent( n+ 1);
        vector<int> rank( n  + 1, 1);


        for( int i = 0; i <= n ; i++){
            parent[i] = i;
        }

        int edgeCount = 0;
        int i = 0;

        int ans = 0;

        while( edgeCount < n - 1  && i < nums.size()){

            auto curr = nums[edgeCount];

            int src = curr[0];
            int dest = curr[1];

            if( src != dest){

                DSU( parent , rank , src , dest);
                edgeCount++;
                ans += curr[2];
            }
            i++;
        }

    return ans;


    }
};
int main(){

    int n = 3;
    vector<vector<int>> nums  = {{1 , 2, 5},{ 1 , 3, 2},{2 , 3, 1}};

    Solution S;

    cout<<S.mini_Cost( n , nums)<<endl;
    return 0;
}