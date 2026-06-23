#include <iostream>
using namespace std;

class Solution{
public:

    int star( vector<vector<int>> & grid){

        int a = grid[0][0];
        int b = grid[0][1];
        int c = grid[1][0];
        int d = grid[1][1];
      
        

        return ( c== a || c == b) ? c : d;

       

      

    }
};
int main(){

    Solution S;

    vector<vector<int>> grid={
        {1,2},{2 , 3},{4 , 2},{ 3 ,1}};

    cout<<S.star(grid)<<endl;
    return 0;
}