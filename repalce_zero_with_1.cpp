#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> convert(vector<vector<int>>& grid) {
        if (grid.empty()) return grid;

        long row = grid.size();
        long col = grid[0].size();
        
        // visited array to keep track of 0s that are connected to the boundary
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> qu;
        vector<vector<int>> ans = grid;

        // Step 1: Push all boundary '0's into the queue and mark them visited
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If it's on the boundary and it is a 0
                if ((i == 0 || j == 0 || i == row - 1 || j == col - 1) && grid[i][j] == 0) {
                    qu.push({i, j});
                    ans[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }

        // Direction vectors for moving: Up, Down, Left, Right
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // Step 2: Standard BFS to find all 0s that can reach the boundary
        while (!qu.empty()) {
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop(); // Fix: Don't forget to pop!

            for (int d = 0; d < 4; d++) {
                int dx = x + dir[d][0];
                int dy = y + dir[d][1];

                // Check boundaries and if the cell is an unvisited '0'
                if (dx >= 0 && dx < row && dy >= 0 && dy < col) {
                    if (grid[dx][dy] == 0 && !visited[dx][dy]) {
                        visited[dx][dy] = true;
                        qu.push({dx, dy});
                        ans[dx][dy] = 1;
                        
                        
                        
                    }
                }
            }
        }

        // Deep copy of grid to create the result
        

//        // Step 3: Flip any '0' that was NOT reached by the boundary BFS to '1'
//        for (int i = 0; i < row; i++) {
//            for (int j = 0; j < col; j++) {
//                if (ans[i][j] == 0 && !visited[i][j]) {
//                    ans[i][j] = 1;
//                }
//            }
//        }

        return ans;
    }
};

int main() {
    Solution S;
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 1},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 1}
    };

    vector<vector<int>> res = S.convert(grid);

    // Print output beautifully
    for (int i = 0; i < res.size(); i++) {
        cout << "{";
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << (j == res[0].size() - 1 ? "" : ", ");
        }
        cout << "}\n";
    }

    return 0;
}
