#include <bits/stdc++.h>
using namespace std;

long long gcd_(long long a, long long b) {
    if (b == 0) return a;
    return gcd_(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    long long maxNum = 0;
    for (int i = 0; i < n; ++i) {
        maxNum = max(maxNum, a[i]);
    }

    for (int i = 0; i < n; ++i) {
        a[i] = maxNum - a[i];
    }

    long long gcdVal = a[0];
    if (n > 1) {
        gcdVal = gcd_(a[0], a[1]);
        for (int i = 2; i < n; ++i) {
            gcdVal = gcd_(gcdVal, a[i]);
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << gcd_(gcdVal, maxNum + b[i]) << ' ';
    }

    cout << '\n';

    return 0;
}
