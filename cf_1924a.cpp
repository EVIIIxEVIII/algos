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
    int n, k, m;
    cin >> n >> k >> m;

    string s;
    cin >> s;

    array<bool, 26> seen;
    seen.fill(false);
    int seen_cnt = 0;

    string ans;
    for (int i = 0; i < m; ++i) {
        if (!seen[s[i]-'a']) {
            seen[s[i]-'a'] = true;
            seen_cnt++;
        }

        if (seen_cnt == k) {
            ans.push_back(s[i]);
            seen.fill(false);
            seen_cnt = 0;
        }
    }

    if ((int)ans.size() >= n) {
        cout << "YES" << '\n';
    } else {
        if (seen_cnt != k) {
            char c;
            for (int i = 0; i < k; ++i) {
                if (!seen[i]) {
                    c = i+'a';
                }
            }
            while ((int)ans.size() < n) {
                ans.push_back(c);
            }
        }
        cout << "NO" << '\n';
        cout << ans << '\n';
    }
}
