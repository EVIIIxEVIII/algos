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

    string s;
    cin >> s;

    vector<long long> a(n);
    for (int i = 0;  i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    // c[0] == a[0]


    long long pref = 0;
    long long max_pref = LLONG_MIN;

    if (s[0] == '0') {
        s[0] = '1';
        a[0] = c[0];
    }

    vector<long long> ans(n);

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            pref += a[i];
            max_pref = max(pref, max_pref);
            ans[i] = a[i];

            if (max_pref != c[i]) {
                cout << "NO" << '\n';
                return;
            }
        } else {
            if (c[i] < max_pref) {
                cout << "NO" << '\n';
                return;
            }

            if (i + 1 < n && s[i + 1] == '1') {
                ans[i] = c[i + 1] - pref - a[i + 1];
                pref += ans[i];
                max_pref = max(max_pref, pref);

                if (max_pref != c[i]) {
                    cout << "NO\n";
                    return;
                }
            } else {
                if (c[i] > max_pref) {
                    ans[i] = c[i] - pref;
                    pref = c[i];
                    max_pref = c[i];
                } else {
                    ans[i] = 0;
                }
            }
        }
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
