//
//  dijkestra_with_diff.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 04/08/26.
//

/*
 You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

 A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

 Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

  

 Example 1:



 Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
 Output: 2
 Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
 This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
 Example 2:



 Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
 Output: 1
 Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
 Example 3:


 Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 Output: 0
 Explanation: This route does not require any effort.
  

 Constraints:

 rows == heights.length
 columns == heights[i].length
 1 <= rows, columns <= 100
 1 <= heights[i][j] <= 106
 */


#include <iostream>
#include <queue>
#include <vector>
#define pp pair< int ,pair< int, int>>
using namespace std;

class Solution{
public:


    
    int minimumEffortPath( vector<vector<int>> & heights){
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        
        vector<vector<bool>> visited( rows , vector<bool> ( cols , false));
        priority_queue<pp , vector<pp> , greater<pp>> pq;
        
        vector<pair< int , int>> directions = {{ 0 , 1} , { 1 , 0} ,{ -1, 0},{ 0 , -1}};
        
        

        vector<vector<int>> effort( rows, vector<int> ( cols , INT_MAX));

        effort[0][0] = 0;
        pq.push({ 0 , { 0 , 0}});
        while (!pq.empty()) {
                auto curr = pq.top();
                pq.pop();
    
                int r = curr.second.first;
                int c = curr.second.second;
    
                // Reached destination (bottom-right cell)
                if (r == rows - 1 && c == cols - 1) {
                    return curr.first;
                }
    
                // Skip processing if a better path to cell (r, c) was already processed
                if (curr.first > effort[r][c]) {
                    continue;
                }
    
                // Explore 4-directional neighbors
                for (const auto& dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;
    
                    // Check grid boundaries
                    if (nr >= 0 && nc >= 0 && nr < rows && nc < cols) {
                        // Maximum effort along the route to cell (nr, nc)
                        int step_diff = abs(heights[r][c] - heights[nr][nc]);
                        int next_effort = max(curr.first, step_diff);
    
                        // If a lower effort path to neighbor (nr, nc) is found
                        if (next_effort < effort[nr][nc]) {
                            effort[nr][nc] = next_effort;
                            pq.push({next_effort, {nr, nc}});
                        }
                    }
                }
            }
    
            return 0;
        }
    };
    
    int main() {
        Solution solver;


        int n,m;
        cin>>n>>m;

        vector<vector<int>> nums( n , vector<int> ( m));

        for( int i = 0; i  < n; i++){
            for( int j = 0; j < m; j++){
                cin>>nums[i][j];
            }
        }
    
        
        cout << " " << solver.minimumEffortPath(nums) << " " << endl;
    
       
        return 0;
    }
    
        
        
        
    
   
