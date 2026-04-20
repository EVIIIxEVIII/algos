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
    string s;
    cin >> s;

    auto check = [&](int k) -> long long {
        vector<bool> used(n);
        int count = k;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                used[i] = true;
                count--;
            }
            if (count == 0) break;
        }

        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                cur--;
                if (cur < 0) return false;
            } else {
                cur++;
            }
        }

        return true;
    };

    int l = 0, r = n;

    // TTFF

    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (l > 0 && s[i] == '1') {
            l--;
        } else ans += i+1;
    }

    cout << ans << '\n';
}
// 13 + 1 + 2 + 9 + 8 + 7 + 6 + 3 + 4
