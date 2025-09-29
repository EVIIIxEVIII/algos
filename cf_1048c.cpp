#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long k, x; cin >> k >> x;

        long long v = (1LL << (k+1)) - x;
        long long c = x;
        long long init = (1LL << k);

        vector<int> ans;

        for (int i = 0; i < 120; ++i) {
            if (v > c) {
                v -= c;
                c *= 2;
                ans.push_back(1);
            } else if (v < c) {
                c -= v;
                v *= 2;
                ans.push_back(2);
            } else {
                break;
            }
        }

        cout << ans.size() << '\n';
        for (int i = ans.size()-1; i >= 0; --i) {
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
