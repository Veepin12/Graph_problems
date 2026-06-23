#include <iostream>
using namespace std;

class Solution {
public:
      void dfs(vector<vector<int>> &image,int currrow,int currcol,int intialcolor,int newcolor){
        
        
        
        int n=image.size(); // ttotal Row
        int m=image[0].size(); //total column
        
        if(currrow<0 || currcol<0 || currrow>=n || currcol>=m) {
            
            
            return; // you are outside the Grid.
        }
        if(image[currrow][currcol]!=intialcolor){
            return; // you are outside the Grid
            
        }
        image[currrow][currcol]=newcolor;
        dfs(image,currrow + 1,currcol,intialcolor,newcolor); //Down
        dfs(image,currrow,currcol+1,intialcolor,newcolor);  // Right
        dfs(image,currrow - 1,currcol,intialcolor,newcolor); // Left
        dfs(image,currrow,currcol - 1,intialcolor,newcolor);   //Up
        
    }
        
    vector<vector<int>> FloodFill(vector<vector<int>> & image,int sr,int sc,int colour){
        if(colour==image[sr][sc]) return image;
        
        dfs(image,sr,sc,image[sr][sc],colour);
        
        return image;
        
        
    }
    
};
int main(){
    Solution S;
    vector<vector<int>> image={
        {1,1,1,0,1},
        {1,1,0,1,1},
        {1,0,1,1,1},
        {0,1,1,1,1},
        {1,1,1,1,0},
    };
    int sc=1;
    int sr=1;
    int colour = 2;
    
    vector<vector<int>> ans = S.FloodFill(image,sr,sc,colour);
    for(int i=0;i<image.size();i++){
        for(int j=0 ; j<image[0].size();j++){
            cout<<image[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}