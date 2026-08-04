#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:

	vector<int> f( vector<int> & nums){
		int n = nums.size();
		stack<int> st;
		vector<int> res ( n , -1);

		for( int i  = n - 1; i >= 0 ; i--){
			
			while( st.size() > 0 &&nums[ st.top()] < nums[i]){
				st.pop();
			}

			if( ! st.empty()) res[i] = nums[st.top()];	
			
			st.push(i);
	}

	return res;
}
};
int  main(){
Solution S;

int n;
cin>>n;
vector<int> nums(n);

for( int i = 0; i < n; i++){
cin>>nums[i];
}

vector<int> r = S.f( nums);

for( int i = 0; i < n; i++){
cout<<r[i]<<" ";
}

return 0;
}
