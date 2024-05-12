#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cards, int k) {
    int n = cards.size();
    int totalsum = 0;
    
    for(int i=0; i<n; i++){
        totalsum+=cards[i];
    }
    int lenofwindow = n-k;
    if(lenofwindow < 1)return totalsum;
    
    int currsum = 0;
    for(int i=0;i<lenofwindow;i++){
        currsum += cards[i];
    }

    int maxsum = totalsum - currsum;

    int i = 0, j = lenofwindow;
    while(j<n){
        currsum -= cards[i];
        currsum += cards[j];
        maxsum = max(totalsum - currsum, maxsum);
        i++;
        j++;
    }
    return maxsum;
}


int main(){
    vector<int>vec = {1, 1000, 1};
    cout<<maxScore(vec, 1);
}