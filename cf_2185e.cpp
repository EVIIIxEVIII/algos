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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    string moves;
    cin >> moves;

    // keep 2 sorted arrays with array 1 being the greatest left offset the robot i can be alive after
    // and array 2 being the greatest right offset the robot i can be alive after
    //
    // have L as -1 and R as 1, add them one by one and for each move if the value is negative b-search in the array 1
    // otherwise in array 2, keep a maximum bound for every i which would be the answer.

    long long inf = 1e18;
    set<pair<long long, int>> left;
    set<pair<long long, int>> right;

    unordered_map<int, pair<long long, long long>> mapp;

    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(b.begin(), b.end(), a[i]);
        long long l = inf;
        long long r = inf;

        if (it != b.begin()) {
            l = a[i] - *(it-1);
        }

        if (it != b.end()) {
            r = *(it) - a[i];
        }

        left.insert({ l, i });
        right.insert({ r, i });
        mapp[i] = {l, r};
    }

    long long current = 0;
    long long ans = n;

    for (int i = 0; i < k; ++i) {
        current += (moves[i] == 'L' ? -1 : 1);

        if (current < 0) {
            auto it = left.upper_bound({ abs(current), INT_MAX });

            int eliminated = 0;
            for (auto i = left.begin(); i != it; ++i) {
                eliminated++;
                int j = (*i).second;
                right.erase({ mapp[j].second, j });
            }

            ans -= eliminated;
            left.erase(left.begin(), it);
        } else {
            auto it = right.upper_bound({ abs(current), INT_MAX });

            int eliminated = 0;
            for (auto i = right.begin(); i != it; ++i) {
                eliminated++;
                int j = (*i).second;
                left.erase({ mapp[j].first, j });
            }

            ans -= eliminated;
            right.erase(right.begin(), it);
        }

        cout << ans << ' ';
    }

    cout << '\n';
}
