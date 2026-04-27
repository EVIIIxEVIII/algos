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

}

vector<int> kahn(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);

    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            indeg[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;

            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)ans.size() != n) {
        return {};
    }

    return ans;
};
