#include<bits/stdc++.h>
using namespace std;

void sol2(int n){    
    for(int i=n; i>0; i--){
        for(int j=0; j<i; j++){
            cout<<i<<"*";
        }
        cout<<endl;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<i<<"*";
        }
        cout<<endl;
    }
}

int main(){
    sol2(4);
}