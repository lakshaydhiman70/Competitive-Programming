#include<bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    cin>>str;

    int sum = 0, two = 0, three = 0;

    for(int i=0; i<str.size(); i++){
        sum += (str[i] - '0') % 9;
        if(str[i] == '2')two++;
        if(str[i] == '3')three++;
    }

    for(int i=0; i <= three; i++){
        for(int j = 0; j <= two; j++){
            int tempSum = sum;
            tempSum += (i * 6) + (j * 2);

            if(tempSum % 9 == 0){
                cout<<"Yes\n";
                return;
            }
        }
    }
    
    cout<<"No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}