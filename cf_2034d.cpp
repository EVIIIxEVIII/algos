#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {

        // idea: the first thing we could do is count the number of 0, 1 and 2 and denote these counts as a, b, c
        // then we would know that the first a positions should be 0, the next b should be 1 and the last c should be 2
        // idea: notice that 1s can be swapped with both 0s and 2s, so we should start with them and then we could use 1s
        // to swap 0s with 2s in 2 moves.
        //
        // idea: we need only one 1 and use it as a bridge to sort 0s and 2s.
        // first we can take a 2 in the 0 segment put them in the 2 segment
        //
        // idea: we only need to fix the 0s segment after than it is 1 move
        // per exchange
        //
        // idea:
        //
        // 0 2 1 0 -> 0 1 2 0

        int n;
        cin >> n;

        vector<int> a(n);
        int z = 0, o = 0, t = 0;

        vector<pair<int, int>> ans;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];

            if (a[i] == 0) z++;
            if (a[i] == 1) o++;
            if (a[i] == 2) t++;
        }

        set<int> zeros;
        for (int i = z; i < n; ++i) {
            if (a[i] == 0) {
                zeros.insert(i);
            }
        }

        for (int i = 0; i < z; ++i) {
            if (a[i] == 1) {
                int last = *prev(zeros.end());
                ans.push_back({ i+1, last + 1 });
                a[last] = 1;
                a[i] = 0;
                zeros.erase(last);
            }
        }

        set<int> ones;
        for (int i = z; i < n; ++i) {
            if (a[i] == 1) {
                ones.insert(i);
            }
        }

        for (int i = 0; i < z; ++i) {
            if (a[i] == 2) {
                int last_one = *prev(ones.end());
                ans.push_back({ i + 1, last_one + 1 });
                ones.erase(last_one);

                int last_zero = *prev(zeros.end());
                ans.push_back({ i + 1, last_zero + 1 });
                zeros.erase(last_zero);

                a[last_one] = 2;
                a[last_zero] = 1;
                a[i] = 0;

                ones.insert(last_zero);
            }
        }

        vector<int> ones_;
        vector<int> twos_;
        for (int i = z; i < z+o; ++i) {
            if (a[i] == 2) {
                twos_.push_back(i);
            }
        }

        for (int i = z+o; i < n; ++i) {
            if (a[i] == 1) {
                ones_.push_back(i);
            }
        }

        for (size_t i = 0; i < ones_.size(); ++i) {
            ans.push_back({ ones_[i] + 1, twos_[i] + 1 });
        }

        cout << ans.size() << '\n';
        for (size_t i = 0; i < ans.size(); ++i) {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }

    return 0;
}
