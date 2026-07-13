#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reach_target(int row, int col) {
        row = abs(row);
        col = abs(col);
        
        if (row == 0 && col == 0) return 0;
        
        // Directions for knight's moves
        vector<pair<int, int>> dir = {
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
        };
        
        // Offset to handle negative coordinates and slightly going out of bounding box
        int offset = 5;
        int max_x = row + 2 * offset;
        int max_y = col + 2 * offset;
        
        vector<vector<bool>> visited(max_x + 1, vector<bool>(max_y + 1, false));
        
        queue<pair<pair<int, int>, int>> qu;
        
        qu.push({{0, 0}, 0});
        visited[0 + offset][0 + offset] = true;
        
        while (!qu.empty()) {
            int x = qu.front().first.first;
            int y = qu.front().first.second;
            int dist = qu.front().second;
            qu.pop();
            
            if (x == row && y == col) {
                return dist;
            }
            
            for (int d = 0; d < 8; d++) {
                int dx = x + dir[d].first;
                int dy = y + dir[d].second;
                
                if (dx >= -offset && dy >= -offset && dx <= row + offset && dy <= col + offset) {
                    if (!visited[dx + offset][dy + offset]) {
                        visited[dx + offset][dy + offset] = true;
                        qu.push({{dx, dy}, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    int x;
    if (cin >> x) {
        int y;
        if (cin >> y) {
            Solution S;
            cout << S.reach_target(x, y) << endl;
        }
    }
    return 0;
}
