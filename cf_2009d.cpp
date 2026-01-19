#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<std::pair<int, int>> v(n);

        std::set<std::pair<int, int>> s;

        long long top_vals = 0;
        long long bottom_vals = 0;

        for (int i = 0; i < n; ++i) {
            cin >> v[i].first;
            cin >> v[i].second;

            if (v[i].second == 0) {
                bottom_vals++;
            } else {
                top_vals++;
            }

            s.insert(v[i]);
        }

        // 1. sort the array by x and then go through it and check if a[i].x == a[i+1].x, if yes, you can construct
        // triagles for all points where p.x < a[i].x and for each point where a[i].x < p.x
        //
        // 2. you have left the triangles where you have something like (1, 0) (2, 1) (3, 0) or the same but with
        // each y reversed.


        sort(v.begin(), v.end(), [](auto& p1, auto& p2) {
            return p1.first < p2.first;
        });

        long long ans = 0;

        for (int i = 0; i < n-1;) {
            auto& [x, y] = v[i];
            auto& [x_n, y_n] = v[i+1];

            if (x == x_n) {
                ans += n - 2;
                i++;
            }

            i++;
        }

        for (int i = 0; i < n; ++i) {
            auto& [x, y] = v[i];

            bool c1 = s.contains({x+1, !y}) && s.contains({x+2, y});

            if (c1) {
                ans++;
            }
        }


        cout << ans << '\n';
    }

    return 0;
}
