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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> t_zeros;
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        int trailing_zeros = 0;
        int num = a[i];
        while (num > 0 && num % 10 == 0) {
            trailing_zeros++;
            num /= 10;
        }

        while (num > 0) {
            num /= 10;
            total++;
        }

        if (trailing_zeros > 0) {
            t_zeros.push_back(trailing_zeros);
        } else {
            while (num > 0) {
                total++;
                num /= 10;
            }
        }
    }

    sort(t_zeros.begin(), t_zeros.end(), greater<int>());

    for (int i = 0; i < (int)t_zeros.size(); ++i) {
        if (i%2 == 1) {
            total += t_zeros[i];
        }
    }


    if (total <= m) {
        cout << "Anna" << '\n';
    } else {
        cout << "Sasha" << '\n';
    }
}
