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
    int n, k, p, q;
    cin >> n >> k >> p >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // would be nice to be able to do it per element, but we are restricted by the window of size k.
    // if we could do it per element however we could just try min((a[i] % p) % q, (a[i] % q) % p)
    //
    // might make sense to firstly find the window of size k with minimum possible sum,
    // and because the elements in that window are already minimized applying either q or p doesn't
    // change their values, so we can just move the window one by one to the left and to the right
    // and apply the operations per element.


    vector<long long> pref_min(n + 1, 0);
    vector<long long> pref_b(n + 1, 0);
    vector<long long> pref_c(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        long long b = (a[i] % p) % q;
        long long c = (a[i] % q) % p;

        pref_min[i+1] = pref_min[i] + min(b, c);
        pref_b[i+1] = pref_b[i] + b;
        pref_c[i+1] = pref_c[i] + c;
    }

    long long ans = LLONG_MAX;

    for (int l = 0; l + k <= n; ++l) {
        int r = l + k;

        long long outside = pref_min[l] + (pref_min[n] - pref_min[r]);
        long long inside_b = pref_b[r] - pref_b[l];
        long long inside_c = pref_c[r] - pref_c[l];

        ans = min(ans, outside + min(inside_b, inside_c));
    }

    cout << ans << '\n';
}
