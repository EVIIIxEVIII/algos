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
            int x; cin >> x;
            a[i] = x;
        }

        sort(a.begin(), a.end());
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == prev+1) {
                prev++;
            }
        }

        cout << ++prev << '\n';

    }

    return 0;
}
