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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = -1;
    int r = -1;
    int max_dec = -1;

    for (int i = 0; i < n; ++i) {
        int local = 0;
        int last = i;
        int max_local = 0;

        for (int j = i+1; j < n; ++j) {
            if (a[i] > a[j]) {
                local++;
                if (local > max_local) {
                    max_local = local;
                    last = j;
                }
            } else if (a[i] < a[j]) {
                local--;
            }
        }

        if (max_dec < max_local) {
            max_dec = max_local;
            l = i+1;
            r = last+1;
        }
    }

    cout << l << ' ' << r << '\n';
}
