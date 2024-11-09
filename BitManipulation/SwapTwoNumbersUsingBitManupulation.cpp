#include<bits/stdc++.h>
using namespace std;

void swapNums(int& a, int& b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(){
    int a = 1, b = 2;
    cout<<"Before: "<<endl;
    cout<<a<<" "<<b<<endl;
    swapNums(a, b);
    cout<<"After: "<<endl;
    cout<<a<<" "<<b<<endl;
}