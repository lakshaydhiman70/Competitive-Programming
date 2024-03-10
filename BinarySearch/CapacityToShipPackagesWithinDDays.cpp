#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> &weights){
    int sum = 0;
    for(auto &res: weights){
        sum+=res;
    }
    return sum;
}

bool isValid(vector<int> &weights, int d, int mid){
    for(auto &res : weights){
        
    }
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = 1, high = sum(weights), mid;
    while(low <= high){
        mid = low + high / 2;
        if(isValid(weights, d, mid)){
            
        }
    }
}

int main(){
    int n = 5;
    int d = 8;
    vector<int>arr = {5, 4, 5, 2, 3, 4, 5, 6};
    cout<<leastWeightCapacity(arr, d);
    //the array contains all the weights that is getting added every day from day 1 to day n.
    //d is the min no of days.
}