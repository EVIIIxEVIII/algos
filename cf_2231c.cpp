#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    unordered_map<int,long long> cnt;
    for (int i = 0; i < n; ++i) {
        int val = a[i];

        unordered_set<int> seen;

        while (true) {
            seen.insert(val);

            if (val % 2) {
                seen.insert(val + 1);
            }

            if (val == 1) break;
            val = (val + 1) / 2;
        }

        for (int x : seen) {
            cnt[x]++;
        }
    }

    auto check = [&](int max_val) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int val = a[i];
            int local = 0;

            while (true) {
                if (val == max_val) {
                    break;
                }

                if (val % 2) {
                    local++;
                    if (val + 1 == max_val) {
                        break;
                    }
                }

                if (val == 1) break;
                local++;
                val = (val + 1) / 2;
            }

            ans += local;
        }
        return ans;
    };

    int ans = INT_MAX;
    for (auto [k, v] : cnt) {
        if (v == n) {
            ans = min(ans, check(k));
        }
    }

    cout << ans << '\n';
}
