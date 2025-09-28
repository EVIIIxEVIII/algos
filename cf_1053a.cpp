#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        int maxNum = 0;
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
            maxNum = max(maxNum, a[i]);
        }

        bool breakEarly = false;
        for (int i = 0; i < m-1; ++i) {
            if (abs(a[i] - a[i+1]) != 1 || a[i] > a[i+1]) {
                breakEarly = true;
            }
        }

        if (breakEarly) {
            cout << 1 << '\n';
            continue;
        }

        cout << n - maxNum + 1 << '\n';
    }
    return 0;
}
