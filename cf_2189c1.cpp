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
    int n; cin >> n;

    vector<int> ans(n+1);

    ans[n] = 1;
    ans[1] = n%2 ? n - 1 : n;
    for (int i = 2; i <= n - 1; ++i) {
        ans[i] = i ^ 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
