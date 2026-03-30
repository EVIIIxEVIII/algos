#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // it is probably pairwise, i.e keep gcd(a[i], a[i-1]) and gcd(a[i], a[i+1]) the same for all i,
    // and remove only prime factors which aren't found in both a[i-1] and a[i+1] from a[i] and also shrink the
    // number of some prime factor p to min(count_p_in_a[i-1], count_p_in_a[i+1]).
    // time complexity n*sqrt(n), as d(n) <= 2*sqrt(n);


    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int left = i > 0 ? gcd(a[i], a[i-1]) : 1;
        int right = i < n - 1 ? gcd(a[i], a[i+1]) : 1;

        // lcm is the max(p[left], p[right]) where p[i] is the number of
        // times the prime p appears in i
        if (lcm(left, right) < a[i]) {
            ans++;
        }
    }

    cout << ans << '\n';
}
