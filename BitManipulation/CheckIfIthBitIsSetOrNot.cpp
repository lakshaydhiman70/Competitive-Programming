#include<bits/stdc++.h>
using namespace std;

bool checkIfIthBitIsSetOrNot(int num, int bit){
    return num & (1<<bit);
}

int main(){
    cout<<checkIfIthBitIsSetOrNot(8, 3);
}