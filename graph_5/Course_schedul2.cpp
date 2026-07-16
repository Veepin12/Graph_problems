
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        vector<int> visited;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited.push_back(node);

            for (int next : adj[node]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if( visited.size() < numCourses){
            return {};
        }

        return visited;
    }
};

int main(){

    Solution S;


    vector<vector<int>> prerequisited = {{1 , 0}};
    int numCourses;
    cin>>numCourses;

    vector<int> res = S.canFinish(numCourses , prerequisited);

    for ( int i = 0; i < res.size(); i++){
        cout<<res[i]<<",";
    }

    return 0;
}