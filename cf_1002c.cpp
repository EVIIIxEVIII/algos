#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<vector<int>> queues(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> queues[i][j];
            }
        }

        long long curr = -1;
        vector<int> buckets(n+1, 0);

        for (int i = 0; i < n; ++i) {
            int seqNum = 0;
            for (int j = n-1; j >= 0; --j) {
                if (queues[i][j] == 1) {
                    seqNum++;
                } else break;
            }

            buckets[seqNum]++;
        }

        int ans = 0;
        int spare = 0;

        for (int i = n; i >= 1; --i) {
            if (buckets[i]) {
                ans++;
                spare += buckets[i]-1;
            } else if (spare) {
                ans++;
                spare--;
            };
        }

        if (ans != n) ans++;

        cout << ans << '\n';
    }

    return 0;
}
