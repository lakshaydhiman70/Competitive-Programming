#include<bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

bool comp(pair<int,int> val1, pair<int,int> val2){
    return val1.second < val2.second;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    vector<pair<int,int>>meet;

    int n = start.size();

    for(int i=0; i<n; i++){
        meet.push_back({start[i], end[i]});
    }

    sort(meet.begin(), meet.end(), comp);

    int ans = 1;
    vector<pair<int,int>>temp;
    temp.push_back(meet[0]);
    stack<pair<int,int>>st;
    st.push(meet[0]);

    for(int i = 1; i<n; i++){
        if(st.top().second < meet[i].first){
            st.push(meet[i]);
        }
    }

    return st.size();
}


int main(){
    vector<int>st = {1, 3, 0, 5, 8, 5}, end = {2, 4, 6, 7, 9, 9};
    cout<<maxMeetings(st, end);
}