#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // idea: the first thing to notice is that the distance between x_j and y_j is at least
        // |x - y|.
        // idea: there is at most one hop between any two cities if city y is reachable from city x.
        // idea: for a given x, y pair we could firstly sort them, where x < y. Then if there exists
        // a city k such that x < k < y and a[k] != a[x] != a[y] then we pick that k, otherwise we need
        // to find the closes city to a[x] or a[y] to the left and to the right respectively such that a[k] != a[x] != a[y].
        // we could use something like a prefix on the indices of each type of city.

        unordered_map<string, vector<int>> prefix;
        prefix["BG"] = vector<int>(n, -1);
        prefix["BR"] = vector<int>(n, -1);
        prefix["BY"] = vector<int>(n, -1);
        prefix["GR"] = vector<int>(n, -1);
        prefix["GY"] = vector<int>(n, -1);
        prefix["RY"] = vector<int>(n, -1);

        prefix[a[0]][0] = 0;
        for (int i = 1; i < n; ++i) {
            for (auto& [k, v] : prefix) {
                if (k == a[i]) {
                    v[i] = i;
                } else {
                    v[i] = v[i-1];
                }
            }
        }

        unordered_map<string, vector<int>> suffix;
        suffix["BG"] = vector<int>(n, n);
        suffix["BR"] = vector<int>(n, n);
        suffix["BY"] = vector<int>(n, n);
        suffix["GR"] = vector<int>(n, n);
        suffix["GY"] = vector<int>(n, n);
        suffix["RY"] = vector<int>(n, n);

        suffix[a[n-1]][n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            for (auto& [k, v] : suffix) {
                if (k == a[i]) {
                    v[i] = i;
                } else {
                    v[i] = v[i+1];
                }
            }
        }

        auto compatible = [](const string& a, const string& b) {
            return (a[0] == b[0] || a[0] == b[1]) || (a[1] == b[0] || a[1] == b[1]);
        };

        auto find_left = [&](int x, int y) {
            int ans = -1;

            for (auto& [k, v] : prefix) {
                if (k == a[x] || k == a[y]) continue;
                ans = max(v[y], ans);
            }

            return ans;
        };

        auto find_right = [&](int x, int y) {
            int ans = n;

            for (auto& [k, v] : suffix) {
                if (k == a[x] || k == a[y]) continue;
                ans = min(v[y], ans);
            }

            return ans == n ? -1 : ans;
        };

        for (int i = 0; i < q; ++i) {
            int x, y;
            cin >> x >> y;

            x--; y--;
            if (x > y) {
                swap(x, y);
            }

            if (compatible(a[x], a[y])) {
                cout << y - x << '\n';
                continue;
            }

            int left = find_left(x, y);
            if (x < left && left != -1) {
                cout << y - x << '\n';
                continue;
            }

            int right = find_right(x, y);
            if (right == -1 && left == -1) {
                cout << -1 << '\n';
            } else if (right == -1) {
                cout << (x - left) + (y - left) << '\n';
            } else if (left == -1) {
                cout << (right - x) + (right - y) << '\n';
            } else {
                if (right - y < x - left) {
                    cout << (right - x) + (right - y) << '\n';
                } else {
                    cout << (x - left) + (y - left) << '\n';
                }
            }
        }
    }

    return 0;
}
