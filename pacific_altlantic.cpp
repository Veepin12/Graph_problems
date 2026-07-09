//
//  multiSourceBFS_DFS.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 06/07/26.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>


using namespace std;


class Solution {

public:
    
    vector<vector<int>> dir = {{1, 0}, { -1 , 0 } , {0 , 1 } , { 0 ,  -1}};
    long row ;
    long col;
    
    vector<vector<int>> h;
    
    
    vector<vector<bool>> bfs( queue<pair<int , int>> & qu){
        
        
        vector<vector<bool>> visited( row , vector<bool> (col , false));
        
        while( ! qu.empty()){
            int x = qu.front().first;
            int y = qu.front().second;
            
            qu.pop();
            visited[x][y] = true;
            
            for( int d = 0; d < 4; d++){
                auto newRow =  x + dir[d][0];
                auto newCol = y + dir[d][1];
                
                if( newRow >= row || newRow < 0 || newCol >= col || newCol < 0) continue; //
                if( visited[newRow][newCol] ) continue;
                
                if( h[newRow][newCol] < h[x][y]) continue;
                
                qu.push( {newRow , newCol});
                
                
                
                
            }
            
            
        }
        return visited;
    }
        
        
    
    
    vector<vector<int>> pacific( vector<vector<int>> & height){
        row = height.size();
        col = height[0].size();
        h = height;
        
        
        // Step of Multi Source BFS;
        vector<vector<int>> h;
        queue<pair<int , int>> pacific;
        queue<pair<int , int>> atlantic;
        
        for( int i = 0 ; i < row ; i++){
            pacific.push({i , 0});
            atlantic.push({i , col-1});
            
        }
        for( int i = 0 ; i < col ; i++){
            pacific.push({0 , i});
            atlantic.push({row - 1 , i});
            
        }
        
        vector<vector<bool>> pacific_res = bfs(pacific);
        vector<vector<bool>> atlantic_res = bfs(atlantic);
        
        vector<vector<int>> result;
        
        for( int i = 0 ; i < row ; i++){
            for( int j = 0 ; j < col ; j++){
                if(pacific_res[i][j] && atlantic_res[i][j]) result.push_back({i , j});
                
            }
        }
        return result;
    }
};
int main(){
    Solution S;
    
    vector<vector<int>> height = {{1 , 2 , 3 , 4 , 5} , {2 , 3 , 3 , 1 , 4}};
    
    vector<vector<int>> res = S.pacific(height);
    
    for( int i = 0 ; i < res.size() ; i++){
        cout<<"{";
        for( int j = 0;  j < res[0].size() ; j++){
            cout<<res[i][j];
        }
        cout<<"}";
    }
    
    
    
    
    return 0;
    
}
