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

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> even;
    vector<long long> odd;

    for (long long i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }

    sort(even.begin(), even.end(), greater<long long>());
    sort(odd.begin(), odd.end(), greater<long long>());
    if (odd.empty()) {
        for (long long i = 1; i <= n; ++i) {
            cout << 0 << ' ';
        }
        cout << '\n'; return;
    }

    if (even.empty()) {
        for (long long i = 1; i <= n; ++i) {
            if (i%2 == 0) {
                cout << 0 << ' ';
            } else {
                cout << odd.front() << ' ';
            }
        }
        cout << '\n'; return;
    }


    vector<long long> prefix(even.size() + 1);
    prefix[0] = 0;
    for (long long i = 1; i <= even.size(); ++i) {
        prefix[i] = prefix[i-1] + even[i-1];
    }

    for (long long i = 0; i <= even.size(); ++i) {
        cout << odd.front() + prefix[i] << ' ';
    }

    for (long long i = 1; i <= (n - (long long)even.size() - 1); ++i) {
        long long need = (i % 2) + i + 1;

        if (need > odd.size()) {
            cout << 0 << ' ';
        } else {
            if (i % 2) {
                cout << odd.front() + prefix[prefix.size()-2] << ' ';
            } else {
                cout << odd.front() + prefix[prefix.size()-1] << ' ';
            }
        }
   }

    cout << '\n';
}
