#include<bits/stdc++.h>
using namespace std;

/*
We have a horizontal number line. On that number line, 
we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. 
Now, we add k more gas stations so that d, 
the maximum distance between adjacent gas stations, is minimized. 
We have to find the smallest possible value of d. 
Find the answer exactly to 2 decimal places.
Note: stations is in a strictly increasing order.

Examples:

Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). 
Adding 2 stations there splits it into approx 4.67. 
The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. 
Now the maximum gap left is 6.
*/


//Brute force solution is here:in this the current time complexity is O(k*N)
//we can reduce this n time complexity where we can remove the second loop by using priority queue datastructure
//that shall make it's time complexity as O(k*LogN)
//we shall store the distance, idx so that we can find the max distance at the top of the queue and shall pick it
double minimiseMaxDistance(vector<int> &arr, int k, int test){
    int n = arr.size();
    vector<int>dist(n-1);
    for(int i=0; i<k; i++){
        long double maxsection = -1;
        int maxidx = -1;
        
        for(int j=0; j<n-1; j++){
            long double diff = arr[j + 1] - arr[j];
            long double sectionlength = diff / (long double)(dist[j] + 1);
            if(sectionlength > maxsection){
                maxsection = sectionlength;
                maxidx = j;
            }
        }

        dist[maxidx]++;
    }

    long  double maxans = -1;
    for(int i=0; i<n-1; i++){
        long double diff = arr[i + 1] - arr[i];
        long double sectionlength = diff / (long double)(dist[i] + 1);
        maxans = max(maxans, sectionlength);
    }

    return maxans;
}


/*
    Checks if it's possible to ensure that the maximum distance between
    consecutive gas stations is at most `mid` by adding at most `k` new stations.

    The condition:
        if ((arr[i] - arr[i-1]) / mid == numberInBetween * mid)
            numberInBetween--;

    handles the case where the gap is an exact multiple of `mid`.
    In such cases, integer division overcounts by one (since the last segment
    already ends exactly at the next station), so we subtract one.
*/
bool isvalid(long double mid, vector<int> arr, int k) {
    int ct = 0; 
    for (int i = 1; i < arr.size(); i++) { 
        int numberInBetween = (arr[i] - arr[i-1]) / mid;
        if ((arr[i] - arr[i-1]) / mid == numberInBetween * mid) {
            numberInBetween--; 
        }
        ct += numberInBetween; 
    }
    return ct <= k; 
}


double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double mxval = 0;
    for (int i = 1; i < n; i++) {
        mxval = max(mxval, (long double)(arr[i] - arr[i - 1]));
    }

    long double low = 0, high = mxval;
    const long double eps = 1e-6;

    while (high - low > eps) {
        long double mid = (low + high) / 2.0;
        if (isvalid(mid, arr, k)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return (double)high;
}


int main(){
    vector<int>arr = {1,2,3,4,5};
    cout<<minimiseMaxDistance(arr, 4);
}