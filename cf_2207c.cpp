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
    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> cnt(n);
    for (int i = 0; i < n; ++i) {
        cnt[i] = h - a[i];

        int max_l = a[i];
        for (int j = i - 1; j >= 0; j--) {
            max_l = max(max_l, a[j]);
            cnt[i] += h - max_l;
        }

        int max_r = a[i];
        for (int j = i + 1; j < n; ++j) {
            max_r = max(max_r, a[j]);
            cnt[i] += h - max_r;
        }
    }

    vector<long long> overlaps(n);
    for (int i = 0; i < n; ++i) {
        long long total_overlap = 0;

        int current = a[i];
        for (int k = i; k < n; ++k) {
            current = max(current, a[k]);
            total_overlap += h - current;
        }

        current = a[i];
        for (int k = i - 1; k >= 0; --k) {
            current = max(current, a[k]);
            total_overlap += h - current;
        }

        overlaps[i] = total_overlap;
    }

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int max_k = i;
        int max_k_val = a[i];

        for (int j = i; j < n; ++j) {
            if (max_k_val < a[j]) {
                max_k_val = a[j];
                max_k = j;
            }

            ans = max(ans, cnt[i] + cnt[j] - overlaps[max_k]);
        }
    }


    cout << ans << '\n';
}
