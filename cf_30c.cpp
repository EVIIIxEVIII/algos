#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        vector<int> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        vector<int> idx(b.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return b[i] < b[j];
        });

        vector<int> b_sorted;
        vector<int> c_sorted;

        for (int i : idx) {
            b_sorted.push_back(b[i]);
            c_sorted.push_back(c[i]);
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(a[i]);
        }

        int ans = 0;
        vector<int> stage2;
        for (int i = 0; i < m; ++i) {
            if (c_sorted[i] == 0) continue;

            while (!pq.empty()) {
                int sword = pq.top();
                pq.pop();

                if (sword >= b_sorted[i]) {
                    int newSword = max(sword, c_sorted[i]);
                    pq.push(newSword);
                    b_sorted[i] = INT_MAX;
                    ans++;
                    break;
                } else {
                    stage2.push_back(sword);
                }
            }
        }

        while(!pq.empty()) {
            stage2.push_back(pq.top());
            pq.pop();
        }

        sort(stage2.begin(), stage2.end());
        sort(b_sorted.begin(), b_sorted.end());

        int j = 0;
        for (int i = 0; i < m; ++i) {
            while (j < n) {
                int sword = stage2[j];
                j++;

                if (sword >= b_sorted[i]) {
                    ans++;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
