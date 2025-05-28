#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n; 
		cin>>n;
		vector<int>vec(n);

		for(int i=0;i<n;i++){
			cin>>vec[i];
		}

		sort(vec.begin(), vec.end());

		if(vec[0] == vec[n-1]){
			cout<<"-1";
		}
		else{

			int idx = 0;

			

			while(vec[idx] == vec[0]){
				idx++;
			}

            cout<<idx<<" "<<n-idx<<endl;
			
			for(int i=0; i<=idx; i++){
				cout<<vec[i]<<" ";
			}	

			cout<<endl;
			
			for(int j=idx+1; j<n;j++){
				cout<<vec[j]<<" ";
			}
		}

		cout<<endl;
	}
}
