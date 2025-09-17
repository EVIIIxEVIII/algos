#include <bits/stdc++.h>

using namespace std;
const int MOD = 998244353;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        long long ans = 1;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) swap(a[i], b[i]);

            if (i == 0 || b[i - 1] <= a[i]) {
                ans = (ans * 2LL) % MOD;
            }         }

        cout << ans << '\n';
    }

    return 0;
}
