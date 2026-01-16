#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;

        std::vector<std::pair<int, int>> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i].first >> a[i].second;
        }

        // idea:
        // use prefix sum to construct a vector where a[r] - a[l] would
        // give the number of distrinct jobs in that period.
        //
        // correction:
        // you need two vectors for this

        std::vector<int> start(n+2, 0);
        std::vector<int> end(n+2, 0);

        for (int i = 0; i < k; ++i) {
            start[a[i].first]++;
            end[a[i].second]++;
        }

        std::vector<int> prefix_start(n + 2, 0);
        std::vector<int> prefix_end(n + 2, 0);

        for (int i = 1; i <= n; ++i) {
            prefix_start[i] = prefix_start[i-1] + start[i];
        }

        for (int i = 1; i <= n; ++i) {
            prefix_end[i] = prefix_end[i-1] + end[i];
        }

        int i_for_mum = 0;
        int i_for_bruh = 0;

        int overlap_for_mum = INT_MAX;
        int overlap_for_bruh = 0;

        for (int l = 1; l + d - 1 <= n; ++l) {
            int r = l + d - 1;

            int overlap = prefix_start[r] - prefix_end[l-1];

            if (overlap_for_bruh < overlap) {
                overlap_for_bruh = overlap;
                i_for_bruh = l;
            }

            if (overlap_for_mum > overlap) {
                overlap_for_mum = overlap;
                i_for_mum = l;
            }
        }

        cout << i_for_bruh << ' ' << i_for_mum << '\n';
    }

    return 0;
}
