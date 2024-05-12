#include<bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& A, int K) {
    int prefix_sum = 0;
    unordered_map<int, int> sums;
    int answer = 0;
    sums[0] = 1;
    for (int num : A) {
        prefix_sum += num;
        int key = prefix_sum % K;
        if (sums.find(key) != sums.end()) {
            answer += sums[key];
            sums[key]++;
            continue;
        }
        sums[key] = 1;
    }
    return answer;
}

int main(){
    vector<int>vec  = {-1, 2, 9};
    cout<<subarraysDivByK(vec, 2)<<endl;
}