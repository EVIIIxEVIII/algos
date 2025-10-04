#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;

        queue<array<int, 2>> koptions;
        koptions.push({rk, ck});

        int rad = 0;

        while (!koptions.empty()) {
            int optionsCount = (int)koptions.size();
            vector<unordered_set<int>> next(n + 1);

            for (int j = 0; j < optionsCount; ++j) {
                auto [cr, cc] = koptions.front(); koptions.pop();

                if (max(abs(cr - rd), abs(cc - cd)) > rad) {
                    next[cr].insert(cc);
                    if (cr + 1 <= n) next[cr + 1].insert(cc);
                    if (cr - 1 >= 0) next[cr - 1].insert(cc);
                    if (cc + 1 <= n) next[cr].insert(cc + 1);
                    if (cc - 1 >= 0) next[cr].insert(cc - 1);
                }
            }

            bool any = false;
            for (int r = 0; r <= n; ++r)
                for (int c : next[r]) { koptions.push({r, c}); any = true; }

            if (!any) break;
            ++rad;
        }

        cout << rad-1 << '\n';
    }
    return 0;
}
