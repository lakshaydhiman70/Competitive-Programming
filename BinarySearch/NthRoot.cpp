//Find the nth root by the provided value using binary search.
#include<bits/stdc++.h>
using namespace std;
const double Eps = 1e-4;

int main(){
    double n = 2;
    double low = 1, high = n, mid;

    while(high - low > Eps){
        mid = (low + high)/2;
        cout<<mid<<endl;
        if(mid * mid < n ){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    // cout<<Eps<<endl;
    // cout<<low<<" "<<high<<endl;
    // cout<<(high - low)<<"\n";
    cout<<setprecision(5)<<high<<endl;
}