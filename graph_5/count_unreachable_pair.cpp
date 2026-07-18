//
//  count_unreachable_pair.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 18/07/26.
//

#include <iostream>
using namespace std;

class Solution{
public:
    
    long long dfs( int node , vector<vector<int>> & adj , vector<bool> & visited ){
        visited[node] = true;
        int size = 1;
        
        for( auto & neighbour : adj[node]){
            if( !visited[neighbour]){
                
                size += dfs( neighbour , adj , visited);
            }
        }
        return size;
    }
    
    long long reach( int n , vector<vector<int>> & nums){
        
        vector<vector<int>> adj(n);
        
        for( auto & ele : nums){
            
            
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
            
        }
        
        vector<bool> visited( n , false);
        vector<long long> comp_size;
        
        for( int i = 0; i < n; i++){
            if(! visited[i]){
                comp_size.push_back(dfs( i , adj , visited));
            }
        }
        
        long long ttpair = 1LL *(n * (n - 1))/2;
        long long ans = 0;
        for( auto size : comp_size){
            ans += (size * (size -1)/2);
        }
        
        
        return ttpair - ans;
    }
    
};
int main(){
    
    int n ;
    cin>>n;
    
    vector<vector<int>> nums = {{0 ,1}, { 0 , 2}, { 1 , 2}};
    
    Solution S;
    
    cout<<S.reach(n , nums);
    return 0;
}
    

