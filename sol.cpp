#include<bits/stdc++.h>
using namespace std;
void swap(vector<int> &v,int low, int high){
    int temp = v[low];
    v[low] = v[high];
    v[high] = temp;
}
int sortPivot(vector<int>&v, int low, int high){
    int n=high;
    int piv = v[low];

    while(low < high){
        if(v[low]>piv){
            swap(v,low,high);
            //continue
        }
        else{
            low++;
        }
        if(v[high]<piv){
            swap(v,low,high);
            //continue;
        }else{
            high--;
        }
        //low++;high--;
    }
    swap(v, 0, low);
    return low;
}

void quickSort(vector<int>&v, int low, int high){
    int pivIdx;
    if(low+1 < high){
        
        pivIdx = sortPivot(v, low, high);
        // cout<<v[pivIdx]<<" "<<pivIdx<<'\n';
        quickSort(v, low, pivIdx-1);
        quickSort(v, pivIdx+1, high);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    quickSort(v, 0, n-1);

    // auto test = sortPivot(v, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}