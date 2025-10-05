#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> l(q);
        vector<int> r(q);

        for (int i = 0; i < q; ++i) {
            cin >> l[i];
            cin >> r[i];
        }

        vector<int> prefix(n);
        prefix[0] = a[0];

        for (int i = 1; i < n; ++i) {
            prefix[i] = a[i] + prefix[i-1];
        }

        for (int i = 0; i < q; ++i) {

        }


    }
    return 0;
}
