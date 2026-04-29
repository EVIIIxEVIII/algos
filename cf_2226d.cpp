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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // if we have a two adjacent number with different parity we can swap them.
    //
    // let x and y be two numbers with the same parity such that x is at position i and y is at position j
    // and we have i < j and x > y (i.e they are an inversion). It is possible to swap x and y iff there exists a number
    // z, s.t x < z or z < y.

    int max_even = INT_MIN;
    int min_even = INT_MAX;

    int max_odd = INT_MIN;
    int min_odd = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) {
            max_odd = max(a[i], max_odd);
            min_odd = min(a[i], min_odd);
        } else {
            max_even = max(a[i], max_even);
            min_even = min(a[i], min_even);
        }
    }

    int max_odd_pref = -1;
    int max_even_pref = -1;

    bool ans = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2) {
            if (a[i] < max_odd_pref && a[i] < min_even && max_odd_pref > max_even) {
                ans = false;
                break;
            }
            max_odd_pref = max(max_odd_pref, a[i]);
        } else {
            if (a[i] < max_even_pref && a[i] < min_odd && max_even_pref > max_odd) {
                ans = false;
                break;
            }
            max_even_pref = max(max_even_pref, a[i]);
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
}
