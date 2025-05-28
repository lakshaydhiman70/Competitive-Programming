#include<bits/stdc++.h>
using namespace std;

vector<int> findMax3(vector<int>&vec){
    vector<int>max3(3, -1);

    for(int i=0; i<vec.size(); i++){
        if(max3[0] == -1 || vec[i] > vec[max3[0]]){
            max3[2] = max3[1];
            max3[1] = max3[0];
            max3[0] = i;
        }
        else if(max3[1] == -1 || vec[i] > vec[max3[1]]){
            max3[2] = max3[1];
            max3[1] = i;
        }
        else if(max3[2] == -1 || vec[i] > vec[max3[2]]){
            max3[2] = i;
        }
    }

    return max3;
}

void solve(){
    int n;
    cin>>n;

    vector<int>a(n), b(n), c(n);

    for(auto &it: a)cin>>it;
    for(auto &it: b)cin>>it;
    for(auto &it: c)cin>>it;
    auto amx3 = findMax3(a);
    auto bmx3 = findMax3(b);
    auto cmx3 = findMax3(c);
    int ans = INT_MIN;

    for(auto &x: amx3){
        for(auto &y: bmx3){
            for(auto &z: cmx3){
                if(x!=y && y!=z && z!=x){
                    ans = max(ans, a[x] + b[y] + c[z]);
                }
            }
        }
    }

    cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}