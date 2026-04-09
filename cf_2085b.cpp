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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int moves = 0;
    vector<pair<int,int>> ans;
    for (int i = 1; i <= n; i+=2) {
        if (i >= n) {
            break;
        }
        if (a[i-1] == 0 || a[i] == 0) {
            ans.push_back({ i-moves, i-moves+1 });
            moves++;
        }
    }

    cout<<ans.size() + (a[n-1] == 0 && n % 2) + (n-moves > 1)<<'\n';
    for (auto [l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }

    if (a[n-1] == 0 && n % 2) {
        cout << n-moves-1 << ' ' << n-moves << '\n';
        moves++;
    }

    if (n-moves > 1) {
        cout << 1 << ' ' << n-moves << '\n';
    }
}
