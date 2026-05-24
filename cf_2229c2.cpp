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

    long long def = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        def += a[i];
    }

    vector<int> ans;

    vector<long long> prefix(n, 0);
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + abs(a[i - 1]);
    }

    vector<long long> suffix(n, 0);
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + a[i + 1];
    }

    int best_idx = -1;
    long long best_val = def;

    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            long long cand = prefix[i] - a[i] + suffix[i];
            if (cand > best_val) {
                best_val = cand;
                best_idx = i;
            }
        }
    }

    if (best_idx == -1) {
        cout << 0 << "\n\n";
        return;
    }

    bool is_pos = true;
    int start = best_idx - 1;
    while (start >= 0 && a[start] < 0) {
        start--;
    }

    for (int i = start; i >= 0;) {
        int j = i;

        if (is_pos) {
            while (j >= 0 && a[j] < 0) {
                j--;
            }
        } else {
            while (j >= 0 && a[j] > 0) {
                j--;
            }
        }

        if (j != -1) {
            ans.push_back(j+1);
        }
        is_pos = !is_pos;
        i = j;
    }
    ans.push_back(best_idx + 1);

    cout << ans.size() << '\n';

    for (int v : ans) {
        cout << v << ' ';
    }
    cout << '\n';
}
