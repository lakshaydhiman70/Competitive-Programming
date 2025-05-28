#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>inp(n);
        unordered_map<int,int>freq;

        for(auto &it: inp){
            cin>>it;
            freq[it]++;
        }

        for(auto &it: freq){
            if(it.second == 1){
                cout<<-1<<"\n";
                // return 0 ;
            }
        }

        vector<int>permu(n);
        for(int i=0;i<n; i++){
            int a = i+1;
            while(i+1<n && inp[i]==inp[i+1]){
                permu[i] = i+1;
                i++;
            }
            permu[i] = a;
        }

        for(int &it: permu){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}