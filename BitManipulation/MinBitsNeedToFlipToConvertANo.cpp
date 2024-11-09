#include<bits/stdc++.h>
using namespace std;

int minbitsToFlip(int& a, int& b){
    int n = a ^ b;
    int count = 0;

    while(n != 0){
        n = n&(n-1);
        count++;
    }
    return count;
}

int main(){
    int a = 8, b = 7;
    cout<<minbitsToFlip(a, b);
}