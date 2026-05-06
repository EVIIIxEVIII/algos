#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>
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
        char c;
        cin >> c;
        a[i] = c-'0';
    }

    vector<int> ans(n);

    // for 1000 1 - 4, 1 * 9 - 3, 1 * 9 * 9 - 2, 1 * 9 * 9 * 9 - 1
    // 1 * 4 + 1 * 9 * 3 + 1 * 9 * 9 * 2 + 1 * 9 * 9 * 9 * 1
    //
    // 100 -> 100 + 10 + 1 -> 111

    // 12345 -> 12345 + 1234 + 123 + 12 + 1
    // digit1 = 5 + 4 + 3 + 2 + 1
    // digit2 = 4 + 3 + 2 + 1
    // digit3 = 3 + 2 + 1

    vector<int> per_digit(n);
    long long init = accumulate(a.begin(), a.end(), 0LL);

    for (int i = n - 1; i >= 0; --i) {
        per_digit[i] = init;
        init -= a[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        ans[n - 1 - i] += per_digit[i];

        long long val = ans[n - 1 - i];
        val /= 10;

        int j = (n - 1 - i) + 1;
        while (val > 0) {
            if (j > (int)ans.size() - 1) {
                ans.push_back(0);
            }
            ans[j] += val % 10;
            val /= 10;
            j++;
        }

        ans[n - 1 - i] = ans[n - 1 - i] % 10;
    }

    bool leading_zs = true;
    for (int i = ans.size() - 1; i >= 0; --i) {
        if (ans[i] != 0) {
            leading_zs = false;
        }

        if (leading_zs) {
            continue;
        }

        cout << ans[i];
    }
    cout << '\n';
}

