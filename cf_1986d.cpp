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

    // addition is always better besides when we have 1
    if (s.size() > 3) {
        for (char d : s) {
            if (d == '0') {
                cout << 0 << '\n';
                return;
            }
        }
    } else if (s.size() == 3 && (s[0] == '0' || s[2] == '0')) {
        cout << 0 << '\n';
        return;
    }

    long long min_max = (s[0]-'0')*10 + (s[1]-'0');
    int min_max_i = 0;

    for (int i = 1; i < n-1; ++i) {
        long long d1 = (s[i]-'0');
        long long d2 = (s[i+1]-'0');
        int num = d1*10 + d2;

        int current_contrib = (d1 > 1 ? d1 : 0) + (d2 > 1 ? d2 : 0);
        int prev_contrib = (min_max%10 > 1 ? min_max%10 : 0) + (min_max/10 > 1 ? min_max/10 : 0);

        if (current_contrib + min_max > num + prev_contrib) {
            min_max = num;
            min_max_i = i;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '1' && i != min_max_i && i != min_max_i+1) {
            ans += s[i]-'0';
        }
    }

    ans = (min_max == 1) ? max(ans,1LL) : ans+min_max;

    cout << ans << '\n';
}
