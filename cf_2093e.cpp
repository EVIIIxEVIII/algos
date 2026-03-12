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

    // idea: first of all the counts are important. If there exists a number a[i] such that count(a[i]) < k then then answer
    // x, x < a[i], otherwise the answer x can be at most max(a[i]) + 1, s.t a[i] >= k.

    // idea: consecutive triples of equal numbers such that a[i] == a[i+1] == a[i+2] or more cannot be used in different
    // partitions, so for each number of consecutive a[i] the count(a[i]) will be count(a[i]) - number of consecutives + 2.

    auto check = [&](int x) {
        int i = 0;
        int splits = 0;

        while (i < n) {
            int count = x + 1;
            set<int> seen;

            int j = i;
            while (j < n && count > 0) {
                if (seen.insert(a[j]).second && a[j] <= x) {
                    count--;
                }
                j++;
            }

            i = j;
            if (count == 0) {
                splits++;
            }
        }

        return splits >= k;
    };

    int l = 0, r = n;

    // mid = (l + r) / 2; l = mid + 1; r = mid;     -> lower bound (smallest value which has condition true)
    while (l < r) {
        int m = l + (r - l) / 2;

        if (check(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << l << '\n';
}
