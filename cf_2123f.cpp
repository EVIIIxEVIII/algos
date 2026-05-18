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

    // tf? can't you just compute the prime numbers in the region [2, n] and then for each one of them
    // we group the numbers by their prime factorization in this way:
    // for 2 we only care about numbers with 2 as a prime factor,
    // for 3 we only care about numbers with at least one 3 and any 2s
    // for 5 we only care about numbers with at least one 5, any 3s and any 2s etc.
    //
    // if a prime number doesn't have such a number in the [2, n] region, i.e for the prime number p, p*2 > n, then
    // we can't do anything and we put p at position p.
    //
    // so the general rule is that for each a[i] we care only about its greatest prime factor.

    unordered_map<int,vector<int>> prime_gr;
    for (int i = 2; i <= n; ++i) {
        int x = i;

        int max_prime_fac = 1;
        while (x % 2 == 0) {
            x /= 2;
            max_prime_fac = 2;
        }

        for (int d = 3; 1LL * d * d <= x; d += 2) {
            while (x % d == 0) {
                x /= d;
                max_prime_fac = d;
            }
        }

        if (x > 1) {
            max_prime_fac = max(x, max_prime_fac);
        }

        prime_gr[max_prime_fac].push_back(i);
    }

    vector<int> ans(n + 1, 1);

    for (auto& [k, v] : prime_gr) {
        if (v.size() == 1) {
            ans[k] = k;
            continue;
        }

        for (int i = 0; i + 1 < (int)v.size(); ++i) {
            ans[v[i]] = v[i + 1];
        }

        ans[v.back()] = v[0];
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
