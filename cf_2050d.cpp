#include <algorithm>
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
    string str;
    cin >> str;

    vector<int> s(str.size());
    for (int i = 0; i < (int)str.size(); ++i) {
        s[i] = str[i]-'0';
    }

    int n = s.size();
    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        int max_j = -1;
        int max_j_val = s[i];

        for (int j = 1; j < 9 && i+j < n; ++j) {
            if (s[i+j]-j > max_j_val) {
                max_j_val = s[i+j]-j;
                max_j = i+j;
            }
        }

        if (max_j != -1) {
            copy_backward(s.begin() + i, s.begin() + max_j, s.begin() + max_j + 1);
            s[i] = max_j_val;
        }
    }

    for (int val : s) {
        cout << val;
    }
    cout << '\n';
}
