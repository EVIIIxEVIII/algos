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

constexpr long long mod = 676767677;
void solve() {
    int n; cin >> n;

    vector<int> a(n);

    long long sum = 0;
    long long ones = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] != 1) sum += a[i];
        else ones++;
    }

    if (ones == 0) {
        cout << sum % mod << '\n';
    } else if (a[n - 1] == 1) {
        cout << (sum + 1) % mod << '\n';
    } else {
        cout << sum % mod << '\n';
    }
}
