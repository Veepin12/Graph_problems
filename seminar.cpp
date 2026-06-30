//
//  freq.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 30/06/26.
//

//
//  Untitled.swift
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 29/06/26.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;



bool seminar( vector<vector<int>> & nums){
    sort( nums.begin() , nums.end());
    if(nums.size()== 1) return true;

    for( int i = 0; i < nums.size() ; i++){
        int check = nums[i][1];
        
    }


       
    
}

int main(){
    vector<vector<int>> nums= {{1 , 3}, { 2 ,6}, { 7 , 8}};
    
    cout<<seminar( nums);
    
   
    
    return 0;
}
