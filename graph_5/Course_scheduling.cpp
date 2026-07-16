//
//  Course_Comp.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 15/07/26.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int visited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            for (int next : adj[node]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return visited == numCourses;
    }
};
int main(){
    
    Solution S;
    
    int numCourse ;
    cin>>numCourse;
    
    vector<vector<int>> prerequisited = {{1 , 0}};
    
    cout<< S.canFinish(numCourse , prerequisited);
    
    return 0;
    
}
