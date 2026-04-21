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

    long long ans = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto step = [&](const vector<long long>& arr) {
        vector<long long> new_arr(n);
        vector<long long> cnt(n+1);

        int current = 0;
        for (int i = 0; i < n; ++i) {
            ans += arr[i];
            cnt[arr[i]]++;
            if (cnt[arr[i]] > 1 && arr[i] > current) {
                current = arr[i];
            }
            new_arr[i] = current;
        }

        return new_arr;
    };


    vector<long long> step1 = step(a);
    vector<long long> inter = step(step1);

    for (int b_l = 0; b_l < n;) {
        int b_r = b_l;
        long long block_sum = 0;

        while (b_r < n && inter[b_r] == inter[b_l]) {
            block_sum += inter[b_r];
            b_r++;
        }

        long long len = (b_r - b_l);
        if (len == 1) {
            ans += inter[b_l];
        } else {
            ans +=
                (n - b_r + 1) * block_sum
                + (block_sum * (b_r - b_l - 1)
                - 1LL * inter[b_l] * (len - 1) * len / 2);
        }

        b_l = b_r;
    }

    cout << ans << '\n';
}
