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

    int j = 1;
    for (int i = 3*n; i >= n+1; i -= 2) {
        cout << i << ' ';
        cout << i-1 << ' ';
        cout << j << ' ';
        j++;
    }

    cout << '\n';
}
