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
    vector<int> b(n);
    vector<int> all(2 * n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all[i] = a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        all[i + n] = b[i];
    }

    sort(all.begin(), all.end());

    auto check = [&](int val) {
        int le = 0;
        int ge = 0;

        for (int i = 0; i < n;) {
            if (b[i] >= val && a[i] >= val) {
                ge++;
                ++i;
            } else {
                int j = i;
                bool has_00 = false;

                while (j < n && (a[j] < val || b[j] < val)) {
                    if (a[j] < val && b[j] < val) {
                        has_00 = true;
                    }

                    j++;
                }

                if (has_00) {
                    le += 1;
                };

                i = j;
            }
        }

        return ge > le;
    };

    int l = 0, r = (int)all.size() - 1;

    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (check(all[m])) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << all[l] << '\n';
}
