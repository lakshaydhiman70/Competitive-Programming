#include<bits/stdc++.h>
using namespace std;
//this problem is same as the book allocation problem that we have previously solved
bool isValid(vector<int>&boards, int k, int mid){
    int sum = 0, workers = 0;
    for(int i = 0; i < boards.size(); i++){
        if(sum + boards[i] <= mid){
            sum += boards[i];
        }
        else{
            workers++;
            sum = boards[i];
        }
    }
    return workers > k;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end()), high = accumulate(boards.begin(), boards.end(), 0), mid;
    while(low <= high){
        mid = (low + high)/2;
        if(isValid(boards, k, mid)){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    int n = 8, k = 2;
    vector<int> arr = {6, 5, 6, 10, 9, 2, 3, 5};
    cout<<findLargestMinDistance(arr, k);
}