//
//  remove_Method_from_project.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 05/08/26.
//
/*
 You are maintaining a project that has n methods numbered from 0 to n - 1.

 You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

 There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.

 A group of methods can only be removed if no method outside the group invokes any methods within it.

 Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

  

 Example 1:

 Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]

 Output: [0,1,2,3]

 Explanation:



 Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

 Example 2:

 Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]

 Output: [3,4]

 Explanation:



 Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

 Example 3:

 Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]

 Output: []

 Explanation:



 All methods are suspicious. We can remove them.

  

 Constraints:

 1 <= n <= 105
 0 <= k <= n - 1
 0 <= invocations.length <= 2 * 10**5
 invocations[i] == [ai, bi]
 0 <= ai, bi <= n - 1
 ai != bi
 invocations[i] != invocations[j]
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // DFS to find all suspicious methods (k and everything invoked by k)
    void dfs(int node, vector<vector<int>>& graph, unordered_set<int>& suspicious) {
        suspicious.insert(node);
        for (int neighbor : graph[node]) {
            if (suspicious.find(neighbor) == suspicious.end()) {
                dfs(neighbor, graph, suspicious);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Build directed graph: graph[i] = methods invoked by method i
        vector<vector<int>> graph(n);
        // Build reverse graph: reverseGraph[i] = methods that invoke method i
        vector<vector<int>> reverseGraph(n);
        
        for (auto& invocation : invocations) {
            int caller = invocation[0];
            int callee = invocation[1];
            graph[caller].push_back(callee);
            reverseGraph[callee].push_back(caller);
        }
        
        // Step 1: Find all suspicious methods (k and all methods invoked by k)
        unordered_set<int> suspicious;
        dfs(k, graph, suspicious);
        
        // Step 2: Check if any non-suspicious method invokes a suspicious method
        for (int suspiciousMethod : suspicious) {
            for (int caller : reverseGraph[suspiciousMethod]) {
                if (suspicious.find(caller) == suspicious.end()) {
                    // A non-suspicious method invokes a suspicious one
                    // Cannot safely remove → return all methods
                    vector<int> result;
                    for (int i = 0; i < n; i++) {
                        result.push_back(i);
                    }
                    return result;
                }
            }
        }
        
        // Step 3: Safe to remove all suspicious methods
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (suspicious.find(i) == suspicious.end()) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    Solution S;
    
    // Test case 1: n=4, k=1, invocations=[[1,2],[0,1],[3,2]]
    // Suspicious: 1, 2 | But 0→1 and 3→2 invoke them → Can't remove → Return [0,1,2,3]
    vector<vector<int>> inv1 = {{1, 2}, {0, 1}, {3, 2}};
    vector<int> res1 = S.remainingMethods(4, 1, inv1);
    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << "\n";
    
    // Test case 2: n=5, k=0, invocations=[[1,2],[0,2],[0,1],[3,4]]
    // Suspicious: 0, 1, 2 | No one invokes them → Remove → Return [3,4]
    vector<vector<int>> inv2 = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
    vector<int> res2 = S.remainingMethods(5, 0, inv2);
    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";
    
    // Test case 3: n=3, k=2, invocations=[[1,2],[0,1],[2,0]]
    // Suspicious: 2, 0, 1 (cyclic) | All are suspicious → Remove all → Return []
    vector<vector<int>> inv3 = {{1, 2}, {0, 1}, {2, 0}};
    vector<int> res3 = S.remainingMethods(3, 2, inv3);
    cout << "Test 3: ";
    for (int x : res3) cout << x << " ";
    cout << "\n";
    
    return 0;
}
