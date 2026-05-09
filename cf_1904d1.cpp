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

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // if a[i] > b[i] then NO


    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout << "NO" << '\n';
            return;
        }
    }


    auto check = [&](int idx) -> bool {
        if (a[idx] == b[idx]) {
            return true;
        }

        for (int i = idx-1; i >= 0; --i) {
            if (a[i] == b[idx]) {
                return true;
            }

            if (b[idx] > b[i] || b[idx] < a[i]) {
                break;
            }
        }


        for (int i = idx+1; i < n; ++i) {
            if (a[i] == b[idx]) {
                return true;
            }

            if (b[idx] > b[i] || b[idx] < a[i]) {
                break;
            }
        }

        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (!check(i)) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
