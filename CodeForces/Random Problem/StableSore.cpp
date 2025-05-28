#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> permutation;
        for (int i = 1; i <= n; i++) {
            permutation.push_back(i);
        }

        // Output the sorted permutation to maximize primality
        for (int i = n; i > 0; i--) {
            cout << permutation[i - 1] << " ";
        }
        cout << endl;
    }

    return 0;
}
