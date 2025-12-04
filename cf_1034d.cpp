#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int totalOnes = 0;
        int ones = 0;

        for (int i = 0; i < n; ++i) {
            totalOnes += (s[i] == '1');
        }

        if (totalOnes <= k || n < 2*k) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
    }
    return 0;
}
