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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> cnt_a(n+1);
    vector<int> cnt_b(n+1);
    for (int i = 0; i < k; ++i) {
        int prev = a[i];
        bool constant = true;
        for (int j = i; j < n; j += k) {
            if (prev != a[j]) {
                constant = false; break;
            }
        }

        if (!constant) {
            for (int j = i; j < n; j += k) {
                if (b[j] != -1 && b[j] != a[j]) {
                    cout << "NO" << '\n';return;
                }
            }
            continue;
        }

        cnt_a[prev]++;

        int val = -1;
        for (int j = i; j < n; j += k) {
            if (b[j] == -1) {
                continue;
            }

            if (val == -1) {
                val = b[j];
            } else if (val != b[j]) {
                cout << "NO" << '\n';
                return;
            }
        }

        if (val != -1) {
            cnt_b[val]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (cnt_b[i] > cnt_a[i]) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}
