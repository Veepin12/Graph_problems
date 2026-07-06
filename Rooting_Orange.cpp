//
//  Rotten_Oranges.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 06/07/26.
//

#include <iostream>
using namespace std;

class Solution{
public:
    
    int OrangeRotting(vector<vector<int>> & grid){
        
        long n = grid.size();
        long m = grid[0].size();
        
        int cc = 0;
        int mins = 0;
        
        queue<pair<int , int>> qu;
       
        
        vector<vector<int>> dir = {{1 , 0}, { 0 , 1}, { - 1, 0}, { 0 , -1}};
        
        
        
        
        for( int i = 0; i < n; i++){
            for( int j = 0; j < m ; j++){
                if(grid[i][j] == 1) cc++;
                if( grid[i][j] == 0) continue;
                
                if( grid[i][j] == 2){
                    qu.push({i , j});
                    
                }
            }
        }
        qu.push({ -1 , -1});
        
        while( ! qu.empty()){
            
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            
            
            if( x == -1 && y == -1){
                mins++;
                if(!qu.empty()){
                    qu.push({ -1 , -1});
                    
                }
                else break;
            }
            for( int d = 0; d < 4 ; d++){
                int i = x + dir[d][0];
                int j = y + dir[d][1];
                
                if( i < 0 || i >= n || j < 0 || j >= m) continue;
                if( grid[i][j] == 0) continue;
                if( grid[i][j] == 2) continue;
                cc--;
                grid[i][j] = 2;
                        
                qu.push({i , j});
                    
                
            }
            
            
        }
        
        return cc== 0 ? mins  - 1: -1;
    }
    
};

int main(){
    Solution S;
    
    vector<vector<int>> grid = {{2 , 1 , 1},{1, 1 , 0},{0 , 1 , 1}};
    cout<<S.OrangeRotting(grid);
    return 0;
}
