#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;

    vector<int>adj[n+1];//its an array of vectors

    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(auto res: adj){
		for(auto val: res){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}