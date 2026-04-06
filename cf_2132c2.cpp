#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

long long pow_(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    // 3^x watermelons for 3^(x+1) + x * 3^(x - 1)

    // 3^19 > 1e9
    array<long long, 20> coeff;
    coeff.fill(0);

    int current = n;
    int total = 0;
    for (int i = 19; i >= 0; --i) {
        long long num = pow_(3, i);

        if (current / num != 0) {
            coeff[i] = current / num;
            total += coeff[i];
            current -= num * (current / num);
        }
    }

    if (total > k) {
        cout << -1 << '\n';
        return;
    }

    k -= total;

    for (int i = 19; i >= 1; --i) {
        if (coeff[i] != 0) {
            long long max_reduction = k / 2;
            long long possible = min(max_reduction, coeff[i]);
            long long cost = possible * 2;

            coeff[i] -= possible;
            coeff[i-1] += possible * 3;
            k -= cost;
        }
    }

    long long ans = 0;
    for (int i = 0; i <= 19; ++i) {
        //cout << i << ' ' << coeff[i] << '\n';
        //cout << i << ' ' << coeff[i] << '\n';
        long long val = coeff[i] * (pow_(3, i+1) + (i > 0 ? i * pow_(3, i - 1) : 0));
        ans += val;
    }

    cout << ans << '\n';
}
