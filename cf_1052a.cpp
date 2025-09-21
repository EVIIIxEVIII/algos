#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> count;
        int curr = a[0];
        count.push_back(1);

        int j = 0;
        for (int i = 1; i < n; ++i) {
            if (curr == a[i]) {
                count[j]++;
            } else {
                count.push_back(1);
                curr = a[i];
                j++;
            }
        }

        sort(count.begin(), count.end());

        long long ans = 0;
        for (int i = 0; i < count.size(); ++i) {
            ans = max((long long)ans, (long long)(1LL * count[i] * (count.size() - i)));
        }

        cout << ans << '\n';
    }
    return 0;
}
