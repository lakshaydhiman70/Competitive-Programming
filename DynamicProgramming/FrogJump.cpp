//https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>dp(N,-1); 
int FrogJump(int n, vector<int>hight){
    if(n==0){
        return 0;
    }
    return FrogJump()
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        cout<<FrogJump(n,vec);
    }
}