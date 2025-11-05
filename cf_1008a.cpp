#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int val; cin >> val;
            sum += val;
        }

        if (sum == x*n) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
