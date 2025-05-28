#include <bits/stdc++.h>
using namespace std;

void moveZeroes(std::vector<int>& nums) {
	int snowBallSize = 0; 
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) {
			snowBallSize++; 
		}
		else if (snowBallSize > 0) {
			int t = nums[i];
			nums[i] = 0;
			nums[i - snowBallSize] = t;
		}

		for(auto &it: nums){
			cout<<it<<" ";
		}
		cout<<endl;
	}
}

int main() {
	vector<int>vec = {2,0,0,1,3,12};
	moveZeroes(vec);
	return 0;
}