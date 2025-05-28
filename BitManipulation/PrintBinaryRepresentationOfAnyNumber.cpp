#include<bits/stdc++.h>
using namespace std;
// Printing the binary representation of any Number.
void pr_binary(int num){
    for(int i=3;i>=0;i--) cout<<((num>>i)&1);
    cout<<endl;
}

void iterative(int num){
    stack<int>st;
    while(num > 1){
        st.push(num%2);
        num /= 2;
    }
    if(num == 1)st.push(1);
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }   
}

int main(){
    pr_binary(9);
    //Update :You can also represent any number in its binary form as;
    //cout<<bitset<const_length>(number);
    cout<<bitset<4>(9)<<endl;
    iterative(5);
}