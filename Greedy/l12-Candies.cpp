#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n <= 1) return n;

    int up = 0, down = 0, peak = 0, ans = 1;

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            up++;
            peak = up;
            down = 0;
            ans += 1 + up;
        } else if (ratings[i] == ratings[i - 1]) {
            up = down = peak = 0;
            ans += 1;
        } else {
            up = 0;
            down++;
            ans += 1 + down - (peak >= down ? 1 : 0);
        }
    }

    return ans;
}

int main() {
    vector<int> v = {1, 0, 2};
    cout << candy(v);
}
