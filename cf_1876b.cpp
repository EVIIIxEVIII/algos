#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}


constexpr long long mod = 998244353;

long  long pow_(long long a, long long b) {
    long long ans = 1;
    a = a % mod;

    while (b > 0) {
        if (b & 1) {
            ans = (__int128)ans * a % mod;
        }

        a = (__int128)a * a % mod;
        b >>= 1;
    }

    return ans % mod;
}
void solve() {
    int n; cin >> n;

    vector<pair<long long,int>> a(n);
    for (int i = 0; i < n; ++i) {
        long long val = 0;
        cin >> val;
        a[i] = {val, i+1};
    }

    sort(a.begin(), a.end(), greater<pair<long long,int>>());

    // go from highest to lowest, and scan all the indices that are divisors of index i,
    // mark those elements as "good", the number of times this element will be "hit" is (2^g - 1) * 2^z
    // where g is the number of "good" indices, ans z the number of "neutral" indices, where neutral is the indices
    // that haven't been used so far, and aren't divisors of i. After that all the "good" indices become bad.

    set<int> bad;
    auto good_indices = [&](int idx) {
        vector<long long> ans;
        for (long long i = 1; i * i <= idx; ++i) {
            if (idx % i == 0) {
                long long bottom = i;
                long long top = idx / i;

                if (bottom == top && !bad.contains(bottom)) {
                    ans.push_back(bottom);
                } else if (bottom != top) {
                    if (!bad.contains(top)) {
                        ans.push_back(top) ;
                    }
                    if (!bad.contains(bottom)) {
                        ans.push_back(bottom) ;
                    }
                }
            }
        }

        return ans;
    };

    long long ans = 0;
    long long neutral = n;

    for (int i = 0; i < n; ++i) {
        auto [val, idx] = a[i];
        if (bad.contains(idx)) continue;

        vector<long long> good = good_indices(idx);
        long long val_hit = pow_(2, (long long)good.size()) - 1;
        val_hit = (__int128)val_hit * pow_(2, neutral - (long long)good.size()) % mod;

        for (long long g : good) {
            bad.insert(g);
        }
        neutral -= (long long)good.size();

        long long sum = (__int128)val_hit * val % mod;
        ans = (ans + sum) % mod;
    }

    cout << ans << '\n';
}
