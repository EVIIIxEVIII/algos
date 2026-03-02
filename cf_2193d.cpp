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
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // idea: answer to the question "how many levels can I pass using
    // x swords".

    vector<int> prefix(n);
    prefix[0] = b[0];

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + b[i];
    }

    // now we need the minimum number of swords to get to prefix[i]
    sort(a.begin(), a.end());

    long long max_score = 0;

    for (int i = 0; i < n; ++i) {
        auto num_swrds = prefix[i];
        if (n - num_swrds < 0) {
            break;
        }

        int min_diff = a[n - num_swrds];
        max_score = max((i + 1LL) * min_diff, max_score);
    }

    cout << max_score << '\n';
}
