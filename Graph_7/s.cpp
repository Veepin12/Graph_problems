//
//  s.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 04/08/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    
    int dfs( int n, vector<bool> & visited , vector<vector<int>> & h){
        visited[n] = true;
        
        int size = 1;
        
        for( auto & neighbour : h[n]){
            if( ! visited[neighbour]){
                size += dfs( neighbour , visited , h);
            }
        }
        
        return size;
    }
    
    int un_vis( int node , vector<vector<int>> & nums){
        
        int n = nums.size();
        
        vector<vector<int>> h( n);
        
        for( auto & ele : nums){
            h[ele[0]].push_back(ele[1]);
            h[ele[1]].push_back(ele[0]);
        }
        
        vector<bool> visited( node , false);
        vector<long long> ans;
        
       
        
        for( int i = 0; i < node ; i++){
            if(! visited[i]){
                ans.push_back(dfs( i  , visited , h));
            }
        }
        
        
        long long ttpair = 1LL *node * (node - 1)/2;
        long long res = 0;
        for( auto size : ans){
            res += (size * (size -1)/2);
        }
        
        
        return (int)ttpair - (int)res;
    }
        
        
    
};

int main(){
    
    int n , m;
    cin>>n>>m;
    vector<vector<int>> nums( n , vector<int> ( m));
    
    for( int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            cin>>nums[i][j];
        }
    }
    int node ;
    cin>>node;
    
    Solution S;
    cout<<S.un_vis( node , nums)<<endl;
    return 0;
}


