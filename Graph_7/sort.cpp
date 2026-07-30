//
//  sort_array_by_freq.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 23/07/26.
//


#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    vector<int> sort_by_freq( vector<int> & nums ){
        
        
        unordered_map< int , int> mp;
        priority_queue<pair< int , int> , vector<pair< int , int>> , greater< pair< int, int>>> pq;
        
        for(auto ele : nums){
            mp[ele]++;
        }
        
        for( auto ele : mp){
            pq.push({ele.second , ele.first});
            
        }
        vector<int> ans;
        
        while( pq.size() > 0){
            
            ans.push_back(pq.top().second);
            
        }
        
        
        return ans;
        
        
        
        
    }
};
int main(){
    int n ;
    cin>>n;
    
    vector<int> nums(n);
    for(int i= 0; i < n; i++){
        cin>>nums[i];
    }
    
    Solution S;
    
    vector<int> res = S.sort_by_freq(nums);
    
    for( int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
