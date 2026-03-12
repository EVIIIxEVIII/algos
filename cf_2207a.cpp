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

    string s;
    cin >> s;

    long long max_ans = (s[0] == '1') + (s[n-1] == '1');
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '1' || (s[i-1] == '1' && s[i+1] == '1')) {
            max_ans++;
            s[i] = '1';
        }
    }

    long long min_ans = max_ans;
    for (int i = 1; i < n - 1; ++i) {
        if ((s[i-1] == '1' && s[i+1] == '1')) {
            s[i] = '0';
            min_ans--;
        }
    }

    cout << min_ans << ' ' << max_ans << '\n';
}
