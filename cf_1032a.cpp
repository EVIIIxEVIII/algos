#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);

        int maxNum = -INT_MAX;
        int minNum = INT_MAX;

        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            maxNum = max(x[i], maxNum);
            minNum = min(x[i], minNum);
        }

        if (maxNum > s && minNum < s) {
            cout << min(maxNum-s, s-minNum)*2 + max(s-minNum, maxNum-s) << '\n';
        } else if (s <= minNum) {
            cout << maxNum - s << '\n';
        } else {
            cout << s - minNum << '\n';
        }
   }

    return 0;
}
