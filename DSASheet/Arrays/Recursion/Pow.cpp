#include<bits/stdc++.h>
using namespace std;

double pow(double x, int y){
    double res = 1;
    while (y > 0)
    {
        if (y & 1){
            res = (res * x);
        }
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

double myPow(double x, int n) {
    double num = 1;
    long long int exp = n; // Convert n to long long int
    if (exp >= 0) {
        num = pow(x, exp);
    } else {
        exp = -exp;
        num = pow(x, exp);
        num = 1.0 / num;
    }
    return num;
}

int main(){
    int n = 'a';
    cout<<n;
    // auto x = 1.00000;
    // auto n = -2147483648;
    // cout << myPow(x, n) << endl;
    return 0;
}