#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    string s;
    cin >> s;

    array<long long, 26+10> cnt;
    cnt.fill(0);

    for (char c : s) {
        if (isdigit(c)) {
            cnt[c-'0']++;
        } else {
            cnt[c+10-'a']++;
        }
    }

    long long ans = 0;
    for (long long ct : cnt) {
        ans += ct * ct;
    }

    cout << ans <<'\n';
}
