#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    vector<pair<int , int>> visited;
    void dfs( vector<vector<int>> & grid , int row , int col , int color , int originalcolor){

        
        if( row < 0 || col < 0 || row > grid.size() || col >= grid[0].size() || grid[row][col] == color  ){
            return ;

        }
        grid[row][col] = -color ;

        dfs( grid ,row + 1 , col , color , originalcolor);
        dfs( grid ,row  , col + 1 , color , originalcolor);
        dfs( grid ,row - 1, col , color , originalcolor);
        dfs( grid ,row , col - 1, color , originalcolor);



        if(!( row == 0 || col == 0 || row < grid.size() - 1 || col < grid[0].size() - 1 || grid[row + 1][col] != -color || grid[row][col + 1] != -color|| grid[row - 1][col] != -color || grid[row ][col - 1] != -color )){
            visited.push_back({ row , col});
        } 
    }

    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row , int col , int color){
        int n  = grid.size();
        int m = grid[0].size();

        int originalcolor = grid[row][col];
        dfs( grid , row , col , color , originalcolor);

        if( originalcolor == color) return grid;

        for( auto  ele : visited){
            int i = ele.first;
            int j = ele.second;

            grid[i][j] = originalcolor;

        }
        for( int i = 0 ; i < grid.size(); i++){
            for( int j = 0 ; grid[0].size() ; j++){
                if(grid[i][j] < 0) grid[i][j] = -1;
            }
        }
        return grid;
     
    }
};
int main(){

    vector<vector<int>> grid = {{1,2,1,2,1,2},{1,2,2,2,1,2},{1,2,2,2,1,2}};
    int row , col , color; 
    cin>>row>>col>>color;

    Solution S;

    vector<vector<int>> res = S.colorBorder(grid , row , col , color);

    for( auto r : res){
        cout<<"{";
        for( auto ele : r){
            cout<<ele<<",";
        }
        cout<<"},";
    }

     return 0;
}




    


