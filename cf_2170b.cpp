#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    long long n; cin >> n;

    vector<long long> b(n);
    long long zeros = 0;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == 0) {
            zeros++;
        }
        sum += b[i];
    }

    cout << min(n - zeros, sum - n + 1) << '\n';
}
