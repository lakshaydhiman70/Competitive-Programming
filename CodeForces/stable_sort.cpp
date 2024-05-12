#include<bits/stdc++.h>
using namespace std;

int main(){
                  //j   i
    vector<int>v = {2, 3, 4, 5, 6 ,7};

    // for (auto &x : v) cout << x << ' ';

    // stable_sort(v.begin(), v.end(), [&](int i, int j){
    //     return true;
    // });

    // for (auto &x : v) cout << x << ' ';
    // cout<<endl;
    
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]<v[j]){
                // iter_swap(v.begin() + i, v.begin() + j);
                swap(v[i],v[j]);
            }
            for(auto &res: v)cout<<res<<" ";
            cout<<endl;
        }
    }
    
    for (auto &x : v) cout << x << ' ';
    cout << endl;
}