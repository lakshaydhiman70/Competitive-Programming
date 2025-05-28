#include<bits/stdc++.h>
using namespace std;

//https://www.naukri.com/code360/problems/boolean-evaluation_1214650?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
/*
    https://takeuforward.org/data-structure/evaluate-boolean-expression-to-true-partition-dp-dp-52/
    Try solving this problem by your own, that shall be helpful to you.
*/
int fun(int i, int j, int isTrue, string &exp, int mod){
    if(i == j){
        if(isTrue){
            return exp[i] == 'T';
        }
        else{
            return exp[i] == 'F';
        }
    }

    int ways = 0;

    for(int ind = i+1; ind < j; ind+=2){
        int lT = fun(i, ind-1, 1, exp, mod);
        int lF = fun(i, ind-1, 0, exp, mod);
        int rT = fun(ind+1, j, 1, exp, mod);
        int rF = fun(ind+1, j, 0, exp, mod);

        if(exp[ind] == '&'){
            if(isTrue){
                ways = (ways + (rT * lT) % mod) % mod;
            }
            else{
                ways = (ways + (rT * lF) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
            }
        }
        else if(exp[ind] == '|'){
            if(isTrue){
                ways = (ways + (rT * lT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else{
                ways = (ways + (rF * lF) % mod)%mod;
            }
        }
        else{
            if(isTrue){
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else{
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
            }
        }
    }

    return ways;
}

int evaluateExp(string & exp) {
    return fun(0, exp.size() - 1, 1, exp, 1e7);
}

int main(){

}