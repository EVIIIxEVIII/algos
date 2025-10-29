#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }


        // n / c > 4, for n, where gcd(c, n) = 1, i.e n is splitable iff n / c > 4, because c, c + (n % c), 2*c, so
        // we can throw away c + (n % c)
        // could use a dp like approach, but can we do better than O(n) memory tho?
    }
    return 0;
}
