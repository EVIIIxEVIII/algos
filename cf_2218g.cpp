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

constexpr long long mod = 676767677;
void solve() {
    long long n, m; cin >> n >> m;
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if (b[0] != 0 && b[1] >= b[0]) {
        cout << 0 << '\n';
        return;
    }

    if (b[n-1] != 0 && b[n-2] >= b[n-1]) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i < n-1; ++i) {
        if (b[i-1] >= b[i] && b[i+1] >= b[i] && b[i] != 0) {
            cout << 0 << '\n';
            return;
        }
    }

    vector<long long> cnt(m);
    for (int i = 0; i < n; ++i) {
        cnt[b[i]]++;
    }

    vector<long long> prefix(m);
    prefix[0] = 0;
    for (int i = 1; i < m; ++i) {
        prefix[i] = prefix[i-1] + cnt[i-1];
    }

    vector<pair<int,int>> min_seat;
    for (int i = 0; i < n; ++i) {
        int left = i-1 >= 0 ? b[i-1] : INT_MAX;
        int right = i+1 < n ? b[i+1] : INT_MAX;

        int min_seat_time = min(left, right);
        min_seat.push_back({ b[i], min_seat_time });
    }

    sort(min_seat.begin(), min_seat.end());
    long long ans = 1;

    for (int i = 0; i < n; ++i) {
        auto [time, min_time] = min_seat[i];
        if (time == 0) continue;

        if (time == min_time + 1) {
            ans = ans * prefix[time] % mod;
        } else {
            ans = ans * cnt[time - 1] % mod;
        }
    }

    cout << ans % mod << '\n';
}
