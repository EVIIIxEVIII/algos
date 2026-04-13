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
    long long n, k; cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i]*1LL;
    }

    // total subarrays = sum(a) - n + 1
    // can be obtained iff after adding k cards we have
    // max(a) - min(a) <= 1 otherwise we have ans = total_subarrays - #(a[i] s.t a[i] - min(a) - 1);

    sort(a.begin(), a.end());

    // TTTTFFFF
    auto check = [&](int i) {
        long long sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += (a[i] - a[j]);
        }
        return sum;
    };

    int l = 0, r = n-1;
    while (l < r) {
        int m = l + (r - l + 1) / 2;

        if (check(m) > k) {
            r = m - 1;
        } else {
            l = m;
        }
    }

    long long spent = check(l);
    long long rem = k - spent;

    long long min_cards_cnt = l + 1;
    long long min_cards = a[l];

    min_cards += rem / min_cards_cnt;
    rem %= min_cards_cnt;

    min_cards_cnt -= rem;

    long long nr_of_cards = min_cards * min_cards_cnt + (min_cards + 1) * (n - min_cards_cnt);
    long long window_size = n;
    long long nr_of_windows = nr_of_cards - window_size + 1;

    cout << nr_of_windows << '\n';
}
