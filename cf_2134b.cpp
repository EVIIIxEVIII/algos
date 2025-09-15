#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long tt; cin >> tt;

    while (tt--) {
        long long n; cin >> n;
        long long k; cin >> k;

        vector<long long> a(n);
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (long long i = 0; i < n; ++i) {
            a[i] = a[i] + (a[i] % (k + 1)) * k;
        }

        for (long long i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}
