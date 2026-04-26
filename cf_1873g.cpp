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
    string s;
    cin >> s;

    // the string can be split into blocks of AAAAB and BAAA

    vector<int> blocks;
    int n = (int)s.size();

    int b_cnt = 0;
    int block = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            block++;
        } else {
            b_cnt++;
            blocks.push_back(block);
            block = 0;
        }
    }

    blocks.push_back(block);
    sort(blocks.begin(), blocks.end(), greater<int>());

    long long ans = 0;
    for (int i = 0; i < b_cnt; ++i) {
        ans += blocks[i];
    }

    cout << ans << '\n';
}
