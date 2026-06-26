
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> qu;
        unordered_set<int> visited;

        qu.push(0);
        visited.insert(0);

        while( ! qu.empty()){
            int curr = qu.front();

            qu.pop();
            visited.insert(curr);

            for( int neighbour : rooms[curr]){
                if( visited.count( neighbour) == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};

int main(){

    Solution S;
    vector<vector<int>> rooms = {{1} , {2} , { 3}, {}};
    cout<<S.canVisitAllRooms(rooms);
    return 0;
}