#include<bits/stdc++.h>
using namespace std;

int bruteForceSol(vector<int>& a, vector<int>& b){

}

//main advance solution
double median(vector<int>& a, vector<int>& b) {
	// Write your main code here.
    if(a.size() > b.size()){
        return median(b, a);
    }
    //here we shall pick low and high based on the no of elements 
    //we need to pick from the first array

    int low = 0, mid1, mid2, high = a.size();
    int n = a.size() + b.size();
    int eleOnTheLeft = (n + 1)/2;

    while(low <= high){
        mid1 = low + high >> 1;
        mid2 = eleOnTheLeft - mid1;
        int l1 = (mid1 - 1) >= 0 ? a[mid1 - 1] : INT_MIN;
        int l2 = (mid2 - 1) >= 0 ? b[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < a.size())? a[mid1] : INT_MAX;
        int r2 = (mid2 < b.size())? b[mid2] : INT_MAX;

        if(l1 > r2){
            high = mid1 -1;
        }
        else if (l1 <= r2 && l2 <= r1){
            if(n%2){
                return max(l1, l2);
            }
            else {
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
        else{
            low = mid1 + 1;
        }
    }
    return 0;
}

int main(){
    int n = 3, m = 2;
    vector<int>a = {1, 2, 2};
    vector<int>b = {2, 4, 4};

    cout<<median(a, b);
}