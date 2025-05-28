#include<bits/stdc++.h>
using namespace std;

bool checkIfIthBitIsSetOrNot(int num, int bit){
    return num & (1<<bit);
}

int setTheIthBit(int& num, int& i){
    return num | (1 << i);
}

int clearTheIthBit(int& num, int& i){
    return num & ~(1 << i);
}

int toggleIthBit(int& num, int& i){
    return num & ~(1 << i);
}

int main(){
    // cout<<checkIfIthBitIsSetOrNot(8, 3);
    int num = 7, i = 2;
    // cout<<setTheIthBit(num, i);
    cout<<clearTheIthBit(num, i);
}