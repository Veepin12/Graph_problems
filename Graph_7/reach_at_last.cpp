//
//  Source_dest.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 16/07/26.
//

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity = T(n) = O(log(n + m)).

// check that if reach the last position on a grid from ( 0 , 0) to ( n -1 , m - 1) with space complexity in O(1)..

class Solution{
public:
    
    bool f( int sr , int sc , int m , int n , vector<vector<char>> & grid){
        
        if( sr == m && sc == n) return true;
        if(sr < 0 || sc < 0 || sr > m || sc > n) return false;
        if(grid[sr][sc] == 'l') return f( sr  , sc - 1, m , n , grid);
        if(grid[sr][sc] == 'r') return f( sr  , sc + 1, m , n , grid);
        if(grid[sr][sc] == 'u') return f( sr - 1 , sc , m , n , grid);
        if(grid[sr][sc] == 'd') return f( sr + 1 , sc , m , n , grid);
        else return false;
        
    }
 
    bool reach( vector<vector<char>> & grid){
        
        int m = grid.size();
        int n = grid[0].size();
        
        return f( 0 , 0 , m - 1 , n - 1  , grid);
    }
};
int main(){
    
    Solution S;
    int n , m;
    cin>>n>>m;

    vector<vector<char>> grid( n , vector<char> (  m ));

    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    
    
    cout<<S.reach(grid)<<endl;
    return 0;
}
