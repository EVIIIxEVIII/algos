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


        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }

        if (sum != n) {
            cout << 0 << '\n';
            continue;
        }


        int curr = 0;
        long long ans = 1;

        for (int i = n-1; i >= 0; --i) {
            if (2*i == n + 1) {
                curr += 1;
            } else if (2*i <= n) {
                curr += 2;
            }

            if (curr < a[i]) {
                ans = 0;
                break;
            }

            ans *= n! / k!(n - k)!;


        }


        cout << "Don't know" << '\n';
    }
    return 0;
}
