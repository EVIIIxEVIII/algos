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
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    // b-search on the free count?
    // b-search on the min moves?
    // b-search on

    sort(a.begin(), a.end(), greater<int>());

    long long moves = 0;
    long long free = sum / 2;

    for (int i = 0; i < n; ++i) {
        if (free - a[i] > 0) {
            moves++;
            sum -= a[i];
            free -= a[i];
        } else {
            if (free > 0) {
                moves++;
                sum -= free;
            }
            moves += sum;
            break;
        }
    }

    cout << moves << '\n';
}
