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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bool non_dec = true;
    for (int i = 1; i < n; ++i) {
        if (a[i-1] > a[i]) {
            non_dec = false;
            break;
        }
    }

    if (non_dec) {
        cout << "Bob" << '\n';
        return;
    }

    int max_pf = 0;
    for (int i = 0; i < n; ++i) {
        int prev = 1;
        int count = 0;

        for (int j = 2; j * j <= a[i]; ++j) {
            while (a[i] % j == 0) {
                if (prev != j) {
                    count++;
                    prev = j;
                }
                a[i] /= j;
            }
        }

        if (a[i] > 1) {
            count++;
            prev = a[i];
        }

        if (count >= 2 || prev < max_pf) {
            cout << "Alice" << '\n';
            return;
        }

        max_pf = max(max_pf, prev);
    }

    cout << "Bob" << '\n';
}
