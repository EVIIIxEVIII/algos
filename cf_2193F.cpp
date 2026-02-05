#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, ax, ay, bx, by;
        cin >> n >> ax >> ay >> bx >> by;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }

        // idea: from the condition we have that the moves we can make are (x + 1), (y + 1) and (y - 1),
        // which means that from point (Ax, Ay) to the point (Bx, By) all the points increase in x value,
        // as the grid is always guaranteed to be traversable.
        //
        // idea: at each "strip" x we can find the point with the minimum y values and the one with the maximum y value
        // because everything in between we would need to traverse anyway.
        //
        // idea: at each point x, we need to decide: is it better to start with the maximum or the minimum and that would
        // allow us to compute the best possible traversal of the grid (probably).

        struct Strip {
            int x;
            int min_y;
            int max_y;
        };

        vector<Strip> state;

        auto add_point = [&](int x, int y) {
            if (state.empty() || state.back().x != x) {
                state.push_back({x, y, y});
            } else {
                state.back().min_y = min(state.back().min_y, y);
                state.back().max_y = max(state.back().max_y, y);
            }
        };

        add_point(ax, ay);

        sort(a.begin(), a.end(), [](auto& p, auto& q) {
            return p.first < q.first;
        });

        for (auto& [x, y] : a) {
            add_point(x, y);
        }

        add_point(bx, by);

        // first -> end low
        // second -> end high
        vector<pair<long long,long long>> dp(state.size());
        dp[0].first = (state[0].max_y - state[0].min_y) + (ay - state[0].min_y);
        dp[0].second = (state[0].max_y - state[0].min_y) + (state[0].max_y - ay);

        for (size_t i = 1; i < state.size() - 1; ++i) {
            long long prev_x = state[i-1].x;
            long long curr_x = state[i].x;
            long long x_dist = curr_x - prev_x;

            long long best_path_low = min(
                x_dist + abs(state[i].max_y - state[i-1].max_y) + dp[i-1].second,
                x_dist + abs(state[i].max_y - state[i-1].min_y) + dp[i-1].first
            );
            dp[i].first = (state[i].max_y - state[i].min_y) + best_path_low;

            long long best_path_high = min(
                x_dist + abs(state[i].min_y - state[i-1].max_y) + dp[i-1].second,
                x_dist + abs(state[i].min_y - state[i-1].min_y) + dp[i-1].first
            );
            dp[i].second = (state[i].max_y - state[i].min_y) + best_path_high;
        }

        long long enter_low = (state.back().max_y - state.back().min_y) + (state.back().max_y - by);
        long long enter_high = (state.back().max_y - state.back().min_y) + (by - state.back().min_y);

        const auto& prev_dp = dp[state.size()-2];
        const auto& prev_state = state[state.size()-2];

        long long prev_x = prev_state.x;
        long long curr_x = state.back().x;
        long long x_dist = curr_x - prev_x;

        enter_low += min(
            prev_dp.first + x_dist + abs(state.back().min_y - prev_state.min_y),
            prev_dp.second + x_dist + abs(state.back().min_y - prev_state.max_y)
        );

        enter_high += min(
            prev_dp.first + x_dist + abs(state.back().max_y - prev_state.min_y),
            prev_dp.second + x_dist + abs(state.back().max_y - prev_state.max_y)
        );

        cout << min(enter_low, enter_high) << '\n';
    }
    return 0;
}
