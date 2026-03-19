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

    vector<int> cnt(n+1);
    int ans = 0;

    int current = 0;
    for (int i = 0; i < n; ++i) {
        cnt[a[i]]++;
        current = max(current, a[i]);
    }

    for (int i = n - 1; i >= 0;) {
        if (current == 0) break;

        if (cnt[current]) {
            while (i >= 0 && cnt[current] > 0) {
                if (a[i] == current) {
                    cnt[current]--;
                    ans++;
                } else {
                    cnt[a[i]]--;
                }
                i--;
            }
        } else {
            current--;
        }
    }

    cout << ans << '\n';
}
