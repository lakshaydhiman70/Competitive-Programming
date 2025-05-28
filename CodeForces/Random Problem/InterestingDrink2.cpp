#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const int MAX_PRICE = 100000;
    vector<int> freq(MAX_PRICE + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        freq[price]++;
    }
    
    for (int i = 1; i <= MAX_PRICE; i++){
        freq[i] += freq[i-1];
    }
    
    int q;
    cin >> q;
    while(q--){
        int m;
        cin >> m;
        if (m >= MAX_PRICE)
            cout << n << "\n";
        else
            cout << freq[m] << "\n";
    }
    
    return 0;
}