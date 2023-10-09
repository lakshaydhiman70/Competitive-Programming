#include<bits/stdc++.h>
using namespace std;

vector<int> UnionTwoVectors(vector<int>vec1, vector<int>vec2){
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    vector<int>UnionVec;

    int i=0,j=0;

    for(;i<min(vec1.size(),vec2.size()) && j<min(vec1.size(),vec2.size());){
        
        if((vec1[i]==vec2[i])){
            UnionVec.push_back(vec1[i]);
            i++;
            j++;
        }

        else if((vec1[i]<vec2[i])){
            UnionVec.push_back(vec1[i]);
            i++;
        }

        else if((vec1[i]>vec2[i])){
            UnionVec.push_back(vec2[i]);
            j++;
        }
    }

    while(i<vec1.size()){
        UnionVec.push_back(vec1[i++]);
    }

    while(j<vec2.size()){
        UnionVec.push_back(vec2[j++]);
    }

    return UnionVec;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;cin>>t;
    
    while(t--){
        int n;cin>>n;
        vector<vector<int>>vec;
        int x;
        while(n--){
            cin>>x;
            vector<int>vec1(x);
            for(int i=0;i<x;i++){
                cin>>vec1[i];
            }
            vec.push_back(vec1);
        }
        
        // for(int i=0;i<vec.size();i++){
        //     for(int j=0;j<vec[i].size();j++){
        //         cout<<vec[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int>test = UnionTwoVectors(vec[0],vec[1]);
        for(int i=0;i<test.size();i++){
            cout<<test[i]<<" ";
        }
    }
    
}