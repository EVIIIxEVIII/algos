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

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        a[i].first = val;
        a[i].second = i;
    }

    // for height h we have pos and cnt
    // so for every height we have:
    // n - (pos[0] + cnt[h]) + n - (pos[0] + cnt[h] - 1) + ...
    // n - pos[0] - cnt[h] + n - pos[1] - cnt[h] + 1 + n - pos[2] - cnt[h] + 2
    //
    // cnt[h]*n - sum(pos) - #cnt[h] * #cnt[h] + (cnt[h] - 1)*cnt[h]/2
    //
    // So for a row at height h we have the displacement
    // cnt[h]*n - sum(pos) - #cnt[h] * #cnt[h] + (cnt[h] - 1)*cnt[h]/2
    //
    // if we have 2 consecutive rows with the same pos then we can just multiply this value
    // by 2, or 3 etc.
    //

    sort(a.rbegin(), a.rend());

    long long cnt = 0;
    long long pos_sum = 0;
    long long cur_h = a[0].first;

    auto row_val = [&]() {
        return cnt * n - pos_sum - cnt * cnt + (cnt - 1) * cnt / 2;
    };

    vector<int> cnt_at_col(n);
    long long base = 0;

    int idx = 0;
    while (idx < n) {
        long long next_h = a[idx].first;
        long long rows = cur_h - next_h;
        base += row_val() * rows;

        int start = idx;

        while (idx < n && a[idx].first == next_h) {
            cnt++;
            pos_sum += a[idx].second;
            idx++;
        }

        for (int j = start; j < idx; ++j) {
            cnt_at_col[a[j].second] = cnt;
        }

        cur_h = next_h;
    }

    base += row_val() * cur_h;

    long long change = LLONG_MIN;

    for (long long i = 0; i < n; ++i) {
        change = max(change, i + cnt_at_col[i] - n);
        // (n - i - 1) - R
        //  L - ((n - i - 1) - R) = L + (n - i - 1 - R) =>
        //  L - n + i + 1 + R, we have L + R + 1 = cnt_at_col[i] =>
        //  - n + i + 1 => cnt_at_col_[i] - n + i
    }

    cout << change + base << '\n';
}
