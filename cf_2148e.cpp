#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        int k; cin >> k;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        set<int> wn;
        unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            map[a[i]]++;
        }

        for (int i = 0; i < n; ++i) {
            if (map[a[i]] % k != 0 || map[a[i]] < k) {
                wn.insert(a[i]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto localMap = map;
            auto localWn = wn;

            unordered_map<int, int> used;

            for (int j = i; j < n; ++j) {
                used[a[j]]++;
                localMap[a[j]]--;

                int remaining = localMap[a[j]] - used[a[j]] * (k-1);

                if (remaining % k == 0 && remaining >= k) {
                    localWn.erase(a[j]);
                } else {
                    localWn.insert(a[j]);
                }

                if (localWn.empty()) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
