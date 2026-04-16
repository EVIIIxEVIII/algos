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

    int idx;
    cin >> idx;

    idx--;
    int left = 0;
    int right = 0;

    int x = !a[idx];

    int current = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i-1]) {
            current = 1;
            if (a[i-1] == x) {
                left += (i-1 < idx) * current;
                right += (i-1 > idx) * current;
            }
        } else {
            current++;
        }
    }

    if (a[n-1] == x && n-1 > idx) {
        right++;
    }

    cout << abs(left - right)*2 + min(left, right)*2 << '\n';
}
