#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        long long k; cin >> k;

        string s;
        s.resize(n);

        vector<long long> a(n);

        for (int i = 0; i < n; ++i) { cin >> s[i]; }
        for (int i = 0; i < n; ++i) { cin >> a[i]; }

        int targetPos = -1;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                targetPos = i;
                a[i] = -1e13;
            }
        }

        long long best = 0;
        long long current = 0;
        for (int i = 0; i < n; ++i) {
            current = max(a[i], current+a[i]);
            best = max(best, current);
        }

        if (best > k || (targetPos == -1 && k != best)) {
            cout << "NO" << '\n';
            continue;
        }

        if (targetPos != -1) {
            long long postfix = 0;
            long long prefix = 0;

            long long before = 0;
            long long after = 0;

            for (int i = targetPos-1; i >= 0; --i) {
                postfix += a[i];
                before = max(postfix, before);
            }

            for (int i = targetPos+1; i < n; ++i) {
                prefix += a[i];
                after = max(prefix, after);
            }

            a[targetPos] = k - before - after;
        }

        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}
