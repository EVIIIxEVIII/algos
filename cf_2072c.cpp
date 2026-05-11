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
    int n, x;
    cin >> n >> x;

    int bit = -1;
    for (int i = 0; i < 31; ++i) {
        if (!((x >> i) & 1)) { // first 0 bit
            bit = i;
            break;
        }
    }

    int max_mex = (1 << bit) - 1; // all obtainable values from 0 till some value s.t orring them still gives x

    int accum = 0;
    vector<int> ans;
    for (int i = 0; i <= max_mex && ans.size() < n; ++i) {
        ans.push_back(i);
        accum |= i;
    }

    if (accum != x && ans.size() == n) {
        ans.pop_back();

        accum = 0;
        for (int val : ans) {
            accum |= val;
        }
        ans.push_back((x^accum));
    } else if (accum != x) {
        ans.push_back(x^accum);
    }

    while (ans.size() < n) {
        ans.push_back(0);
    }

    for (int v : ans) {
        cout << v << ' ';
    }

    cout << '\n';
}
