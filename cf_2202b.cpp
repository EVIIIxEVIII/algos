#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string x;
        cin >> x;
        // idea: because of the algorithm there can be at most 2 same consecutive characters aa or bb.

        if (n % 2 == 1 && x[0] == 'b') {
            cout << "NO" << '\n';
            continue;
        }

        int start = (n % 2 == 1) ? 1 : 0;

        bool ok = true;
        for (int i = start; i + 1 < n; i += 2) {
            char a = x[i];
            char b = x[i+1];

            if (a != '?' && b != '?' && a == b) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
