#include<bits/stdc++.h>
using namespace std;
void subsetSumI(int idx, vector<int>&v, int sum,vector<int>&vec){
    if(idx >= v.size()){
        vec.push_back(sum);
        return;
    }
    subsetSumI(idx+1,v, sum+v[idx],vec);
    subsetSumI(idx+1,v, sum,vec);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>vec;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    subsetSumI(0, v, 0, vec);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
}
//estimates are only to groom the story