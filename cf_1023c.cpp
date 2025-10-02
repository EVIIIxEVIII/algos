#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int k; cin >> k;

        string s;
        s.resize(n);

        vector<int> a(n);

        for (int i = 0; i < n; ++i) { cin >> s[i]; }
        for (int i = 0; i < n; ++i) { cin >> a[i]; }


        int best = INT_MIN;
        int current = 0;

        vector<int> currents(n, 0);
        vector<int> frees;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                current = 0;
                frees.push_back(i);
                continue;
            }

            if (current + a[i] < 0) {
                current = a[i];
            } else {
                current += a[i];
            }

            currents[i] = current;
            best = max(best, current);
        }

        if (best > k || (!frees.size() && k != best)) {
            cout << "NO" << '\n';
            continue;
        } else if (!frees.size() && k == best) {
            cout << "YES" << '\n';
            for (int i = 0; i < n; ++i) cout << a[i] << ' ';
            cout << '\n';
            continue;
        } else {
            cout << "YES" << '\n';
        }

        int targetPos = frees[0];
        int before = max(targetPos-1 >= 0 ? currents[targetPos-1] : 0, 0);
        int after = 0;

        for (int i = targetPos; i < n; ++i) {
            if (i > targetPos+1 && currents[i] == a[i]) break;
            after = max(currents[i], after);
        }

        for (int i = 0; i < frees.size(); ++i) {
            a[frees[i]] = INT_MIN;
        }

        cout << "After: " << after << '\n';

        a[targetPos] = k - (before + after);

        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}
