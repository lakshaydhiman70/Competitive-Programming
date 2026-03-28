#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        int maxArea = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty()? -1: st.top();
                maxArea = max(arr[element] * (nse - pse - 1), maxArea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int element = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1)* arr[element]);
        }

        return maxArea;
    }

int main(){
    vector<int>temp = {3,2,5,6,2};
    cout<<largestRectangleArea(temp);
}