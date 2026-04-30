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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int min_val = a[n-1];

    long long ans = 0;
    int streak = 0;
    int max_streak = 0;

    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > min_val) {
            ans += a[i] - min_val;
        }

        if (a[i] >= min_val) {
            streak++;
        } else {
            min_val = a[i];
            max_streak = max(max_streak, streak);
            streak = 0;
        }
    }
    max_streak = max(max_streak, streak);

    cout << ans + max_streak << '\n';
}
