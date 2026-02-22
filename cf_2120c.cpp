#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // idea: so m can be between from n (inclusive) to (n + 1) * n / 2 (inclusive);
        // otherwise it is not possible
        //
        // how do I build it now?
        //
        // idea: for something like n = 4 I can have 1 1 1 1, then 2 1 1 1, then 3 1 1 1, then 4 1 1 1
        // etc.
        // after that I have 4 2 1 1, then 4 3 1 1, 4 3 2 1

        if (m < n || m > (n + 1LL) * n / 2LL) {
            cout << -1 << '\n';
            continue;
        }

        std::vector<int> ans(n, 1);
        m -= n;

        int i = 0;
        while(m > 0 && i < n) {
            long long have = n - (i + 1);
            long long add = min(have, m);
            ans[i] += add;
            m -= add;
            i++;
        }

        set<int> unused;
        for (int i = 1; i <= n; ++i) {
            unused.insert(i);
        }

        cout << ans[0] << '\n';
        int last = ans[0];

        for (int i = 0; i < n-1; ++i) {
            if (ans[i] != 1) {
                unused.erase(ans[i]);
                unused.erase(ans[i+1]);
                last = ans[i+1];

                cout << ans[i] << ' ' << ans[i+1] << '\n';
            }
        }

        for(int x : unused) {
            cout << last << ' ' << x << '\n';
            last = x;
        }
    }
    return 0;
}
