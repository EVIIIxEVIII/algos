#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        int zeros = 0;
        int nagatives = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0) {zeros++;}
            if (a[i] == -1) {nagatives++;}
        }

        cout << zeros + (nagatives % 2 == 1 ? 2 : 0) << '\n';
    }
    return 0;
}
