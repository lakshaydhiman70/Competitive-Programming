#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	
	vector<int>ans;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		
		if(i != 0 && ans.back() > x){
			ans.push_back(1);
		}

		ans.push_back(x);
	}
	cout<<ans.size()<<endl;
	for(auto ele: ans){
		cout<<ele<<" ";
	}
	cout<<endl;
}	

int main() {
	int t;
	cin>>t;
	while(t--){
		solve();
		
	}
	return 0;
}