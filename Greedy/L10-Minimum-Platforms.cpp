#include<bits/stdc++.h>
using namespace std;
int minPlatform(vector<int>& arr, vector<int>& dep) {
    int i = 1, j = 0;
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 1, arrival = 1;
    int n = arr.size();
    
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            arrival++;
            i++;
        }
        else{
            arrival--;
            j++;
        }

        platforms = max(platforms, arrival);
    }

    return platforms;
}

int main(){
    vector<int>v1 = {900, 940, 950, 1100, 1500, 1800}, v2 = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<minPlatform(v1 ,v2);
}