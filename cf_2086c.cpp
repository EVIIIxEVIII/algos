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
    vector<int> p(n+1);
    vector<int> d(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    set<int> seen;
    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
        int rem = d[i];
        if (!seen.insert(rem).second) {
            cout << ans << ' ';
            continue;
        }

        long long add = 1;
        int curr = p[rem];
        while (curr != rem) {
            seen.insert(curr);
            add++;
            curr = p[curr];
        }

        ans += add;
        cout << ans << ' ';
    }

    cout << '\n';
}
