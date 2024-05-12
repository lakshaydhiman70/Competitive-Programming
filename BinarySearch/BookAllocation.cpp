#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int>&books, int noOfPages, int noOfStuds){
    int sum = 0;
    int student = 1;
    for(int i=0 ;i<books.size();i++){
        if(sum + books[i] <= noOfPages){
            sum += books[i];
        }
        else{
            student++;
            sum = books[i];
        }
    }
    return student  > noOfStuds;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n)return -1;
    int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0), mid;
    while(low <= high){
        mid = (low + high)/2;
        if(isValid(arr, mid, m)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

int main(){
    int n = 5, m = 4;
    vector<int>arr = {25, 46, 28, 49, 24};
    cout<<findPages(arr, n, m);
}