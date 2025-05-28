#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int                 long long
#define FAST_IO             (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define vi vector<int>
#define fr(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

int getMaxConsecutiveCount(const string& str, char ch) {
    int maxCount = 0, count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }
    return maxCount;
}
