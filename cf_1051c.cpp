#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;

        vector<int> u(n);
        vector<int> v(n);
        vector<int> x(n);
        vector<int> y(n);

        for (int i = 0; i < n-1; ++i) {
            cin >> u[i];
            cin >> v[i];
            cin >> x[i];
            cin >> y[i];
        }

        vector<bool> used(n+1);
        for (int i = 0; i <= n; ++i) used[i] = false;
        deque<int> ans;

        for (int i = 0; i < n-1; ++i) {
            if (x[i] > y[i]) {
                if (!used[u[i]]) {
                    ans.push_back(u[i]);
                    used[u[i]] = true;
                }

                if (!used[v[i]]) {
                    ans.push_front(v[i]);
                    used[v[i]] = true;
                }
            } else {
                if (!used[u[i]]) {
                    ans.push_front(u[i]);
                    used[u[i]] = true;
                }

                if (!used[v[i]]) {
                    ans.push_back(v[i]);
                    used[v[i]] = true;
                }
            }
        }

        for (auto x : ans) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
