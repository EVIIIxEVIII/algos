#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> p(n);
        vector<int> s(n);

        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        // first idea: p can only decrease and s can only decrease
        bool ans = p[n-1] == s[0];
        for (int i = 1; i < n; ++i) {
            if (p[i-1] < p[i] || s[i-1] > s[i]) {
                ans = false;
                break;
            }
        }

        // take away:
        // 1. always try to normalize and array when you have a gcd problem on the array
        // 2. if you have gcd(a_i, p_i-1) = p_i and also gcd(a_i, s_i+1) = s_i, then a_i is a
        // common multiple of p_i and s_i
        // 3. a safe way to contruct an a_i would be by doing a_i = s_i * p_i * g, where g is the initial
        // normalization coefficient and p_i and s_i are already normalized

        for (int i = 1; i < n; ++i) {
            if (p[i - 1] % p[i] != 0 || s[n - i] % s[n - i - 1] != 0) {
                ans = false;
            }
        }

        if (!ans) {
            cout << "NO" << '\n';
            continue;
        }

        int g = p[n-1];
        for (int i = 0; i < n; ++i) {
            p[i] = p[i] / g;
            s[i] = s[i] / g;
        }

        for (int i = 1; i < n; ++i) {
            if (gcd(p[i-1]/p[i], s[i]) != 1 || gcd(s[i]/s[i - 1], p[i-1]) != 1) {
                ans = false;
                break;
            }
        }

        if (!ans) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}
