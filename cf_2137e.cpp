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

    // main take away: if all possible inputs collapase into a cyclical pattern after some n moves it
    // makes sense to simulate the problem for n + 2 moves and use the previous and the previous previous to
    // get the answer.

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto step = [&]() {
        int mex = 0;
        sort(a.begin(), a.end());
        vector<int> cnt(n+1);
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }

        for (int i = 0; i <= n; ++i) {
            if (cnt[i] == 0) {
                mex = i; break;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (cnt[a[i]] > 1 || a[i] > mex) {
                a[i] = mex;
            }
        }
    };

    step();
    if (k == 1) {
        cout << std::accumulate(a.begin(), a.end(), 0LL) << '\n';
        return;
    }

    step();
    long long prev = std::accumulate(a.begin(), a.end(), 0LL);
    if (k == 2) {
        cout << prev << '\n';
        return;
    }

    step();
    long long curr = std::accumulate(a.begin(), a.end(), 0LL);
    if (k == 3) {
        cout << curr << '\n';
        return;
    }

    k -= 3;

    if (k % 2 == 1) {
        cout << prev << '\n';
    } else {
        cout << curr << '\n';
    }
}
