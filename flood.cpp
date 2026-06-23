#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &grid , int sr , int sc, int initialcolor ,int color){
        

        int n = grid.size();
        int m = grid[0].size();

        if( sr < 0 || sc < 0 || sr >= n || sc>= m ){
            return;
        }
        if( grid[sr][sc] != initialcolor){
            return;
        }

        grid[sr][sc] = color;

        dfs(grid, sr + 1, sc ,initialcolor, color);
        dfs(grid, sr, sc + 1 ,initialcolor, color);
         dfs(grid, sr - 1, sc ,initialcolor, color);
         dfs(grid, sr , sc - 1,initialcolor, color);



    }


    vector<vector<int>> floodfill( vector<vector<int>>& grid , int sr , int sc , int color){
        if(color == grid[sr][sc]) return grid;
        dfs( grid , sr , sc ,grid[sr][sc],color );
        return grid;


    }
};

int main(){
    Solution S;
    vector<vector<int>> grid={
        {1,1,1,0,1},
        {1,1,0,1,1},
        {1,0,1,1,1},
        {0,1,1,1,1},
        {1,1,1,1,0},
    };
    int sc=3;
    int sr=4;
    int colour = 2;
    
    vector<vector<int>> ans = S.floodfill(grid,sr,sc,colour);
    for(int i=0;i<grid.size();i++){
        for(int j=0 ; j<grid[0].size();j++){
            cout<<grid[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}

