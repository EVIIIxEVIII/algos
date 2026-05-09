#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        // bsearch? FFTT style
        // check is just a dfs or some shit?
        // dfs proly n^2...  and more complex that 0/1 BFS stuff

        vector<vector<pair<int,int>>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        auto check = [&](int t) {
            vector<int> dist(n, INT_MAX);
            dist[source] = 0;

            deque<int> dq;
            dq.push_back(source);

            while (!dq.empty()) {
                int u = dq.front();
                dq.pop_front();

                for (auto& [v, w] : g[u]) {
                    if (dist[v] > dist[u] + (w > t)) {
                        dist[v] = dist[u] + (w > t);

                        if (w <= t) {
                            dq.push_front(v);
                        } else {
                            dq.push_back(v);
                        }
                    }
                }
            }

            return dist[target] <= k;
        };

        int l = 0, r = 1e9 + 7;// nice primmmeeee should be ok? bc max w is 1e9

        while (l < r) {
            int m = l + (r - l) / 2;

            if (check(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l == 1e9+7 ? -1 : l;
    }
};
