#include <iostream>
#include <queue>
using namespace std;



class Solution {
    public:

    int numIsland( vector<vector<char>> & grid){
        int row = grid.size();
        int col = grid[0].size();

        int cc = 0; // coonnected component .

        
       for( int r = 0; r < row ; r++){
            for( int  c= 0; c < col ; c++){
                if( grid[r][c] == '0') continue;
                



                cc++;

            

                queue<pair<int, int >> qu ;
                qu.push({r , c});
                while( ! qu.empty()){
                    int x = qu.front().first;
                    int y = qu.front().second;
                    qu.pop();

                    // check up .

                    if( x + 1 < row && grid[x + 1][ y] == '1'){
                        qu.push({ x + 1, y});
                        grid[x + 1][y] = '0';

                    }
                    // check down.
                    if( x - 1 >= 0 && grid[x - 1][ y] == '1'){
                        qu.push({ x - 1, y});
                        grid[x - 1][y] = '0';

                    }
                    // check left.
                     if( y - 1 >= 0 && grid[x ][ y - 1] == '1'){
                        qu.push({ x , y - 1});
                        grid[x ][y - 1] = '0';

                    }
                    // check right.
                     if( y + 1 < col && grid[ x][ y + 1] == '1'){
                        qu.push({ x , y + 1});
                        grid[x][y + 1] = '0';

                    }
                }
               
            }
        }




    return cc;



    }
};
int main(){

    vector<vector<char>> grid = {{'1', '1', '1' , '0'}, {'1', '0', '1' , '0'},{'0', '0', '0' , '0'}};
    Solution S;

    cout<<S.numIsland( grid);
    return 0;
}