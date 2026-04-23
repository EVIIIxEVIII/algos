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
    string s;
    cin >> n >> k >> m >> s;

    const int INF = INT_MAX - 10;

    auto last_char = [&](int idx) -> pair<int, char> {
        int latest = idx;
        char c_ans = 'a';

        for (char c = 'a'; c < 'a'+k; ++c) {
            int found_idx = INF;
            for (int i = idx; i < m; ++i) {
                if (s[i] == c) {
                    found_idx = i;
                    break;
                }
            }

            if (latest < found_idx) {
                c_ans = c;
                latest = found_idx;
            }
        }

        return {latest, c_ans};
    };


    string ans;
    int start = -1;
    for (int i = 0; i < n; ++i) {
        auto [idx, c] = last_char(start+1);
        start = idx;

        ans.push_back(c);
        if (start == INF) {
            cout << "NO" << '\n';

            for (char ch : ans) {
                cout << ch;
            }
            for (int j = 0; j < n - (int)ans.size(); ++j) {
                cout << c;
            }
            cout << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
