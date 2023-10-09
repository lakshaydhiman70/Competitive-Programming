#include<bits/stdc++.h>
using namespace std;

int factorialOfN(int n, vector<int>&numbers){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans*=i;
        numbers.push_back(ans);
    }
    return ans;
}

/// @brief 
/// @param n 
/// @param k 
/// @return 
string KthPermutation(int n, int k){
    vector<int>numbers;
    int fact = 1;
    for(int i=1;i<n;i++){
        fact=fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k=k-1;
    while(true){
        ans = ans+to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0)break;
        k=k%fact;
    }
    return ans;
}

int main(){
    int n = 4, k=17;
    string ans = KthPermutation(n, k);
    cout<<ans<<endl;
}

//For n = 4, total no of permutations shall be = 24 (4!) 

//and we need to find the 17th permutation so we shall check for
//16th permutation as we have the zero based indexing

// 1 + (2, 3, 4) --> 6 (0 - 5)

// 2 + (1, 3, 4) --> 6 (6 - 11)

// 3 + (1, 2, 4) --> 6 (12 - 17)

// 4 + (1, 2, 3) --> 6 (18 - 24)

// for the 16th permutation we just need to find the in which section shall it falls
// in the 3rd section it falls

// 3 + (1, 2, 4)