#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m;
    cin >> m;

    // main take away from this problem:
    // when you have two paths where one path is the complement of the other path
    // the minimum distance between any two nodes using any path is 1

    vector<vector<int>> railway(n+1, vector<int>{});
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        railway[u].push_back(v);
        railway[v].push_back(u);
    }

    vector<vector<int>> roads(n+1, vector<int>{});
    for (int i = 1; i <= n; ++i) {
        set<int> seen(railway[i].begin(), railway[i].end());

        for (int j = i + 1; j <= n; ++j) {
            if (!seen.count(j)) {
                roads[i].push_back(j);
                roads[j].push_back(i);
            }
        }
    }

    vector<int> distRailway(n+1, -1);
    distRailway[1] = 0;

    queue<int> bfs;
    bfs.push(1);

    while (!bfs.empty()) {
        int vert = bfs.front();
        bfs.pop();

        for (auto u : railway[vert]) {
            if (distRailway[u] == -1) {
                distRailway[u] = distRailway[vert] + 1;
                bfs.push(u);
            }
        }
    }

    vector<int> distRoads(n+1, -1);
    distRoads[1] = 0;

    bfs = queue<int>();
    bfs.push(1);

    while (!bfs.empty()) {
        int vert = bfs.front();
        bfs.pop();

        for (auto u : roads[vert]) {
            if (distRoads[u] == -1) {
                distRoads[u] = distRoads[vert] + 1;
                bfs.push(u);
            }
        }
    }

    if (distRailway[n] != -1 && distRoads[n] != -1) {
        cout << max(distRailway[n], distRoads[n]) << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}

