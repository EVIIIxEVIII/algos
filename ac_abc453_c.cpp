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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto check = [&](int bitmask) -> int {
        double init = 0.5;
        int local_ans = 0;
        for (int i = 0; i < n; ++i) {
            double local = init;
            local += ((bitmask >> i) & 1) ? -a[i] : a[i];
            local_ans += (local > 0) != (init > 0);
            init = local;
        }
        return local_ans;
    };

    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        ans = max(ans, check(i));
    }

    cout << ans << '\n';
}
