#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {

        int n; cin >> n;
        int k; cin >> k;

        vector<long long> s(n);
        vector<long long> t(n);

        for (int i = 0; i < n; ++i) cin >> s[i];
        for (int i = 0; i < n; ++i) cin >> t[i];

        if (k == 0) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            cout << (s == t ? "YES\n" : "NO\n");
            continue;
        }


        vector<long long> ks(n), kt(n);

        for (int i = 0; i < n; ++i) {
            long long r = ((s[i] % k) + k) % k;
            long long m = (k - r) % k;
            ks[i] = min(r, m);
        }

        for (int i = 0; i < n; ++i) {
            long long r = ((t[i] % k) + k) % k;
            long long m = (k - r) % k;
            kt[i] = min(r, m);
        }

        sort(ks.begin(), ks.end());
        sort(kt.begin(), kt.end());

        cout << (ks == kt ? "YES\n" : "NO\n");
    }

    return 0;
}

