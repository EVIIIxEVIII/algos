#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<long long> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    int q; cin >> q;
    vector<long long> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
    }

    // so the semaphores are red at t % k == d[i], where t is time.

    // is this some kind of directed graph thing? and the problem is to check if this directed
    // graph has a cycle in it, or smth like that?

    // you firstly can construct a graph out of these traffic lights and then for each starting position
    // we can basically check if we find a red traffic light if we do then we traverse the graph from the node
    // corresponding to that traffic light.
    //
    // no way this shit aced on god

    struct Node {
        long long left_next = -1;
        long long right_next = -1;
    };

    // 1002 so r - l + 1 = d[r]?
    // (d[l] + (r - l)) % k == d[r]?

    vector<Node> g(n);
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            if (g[l].right_next == -1 && (d[l] + (p[r] - p[l])) % k == d[r]) {
                g[l].right_next = r;
            }

            if ((d[r] + (p[r] - p[l])) % k == d[l]) {
                g[r].left_next = l;
            }
        }
    }

    // commig_right = true => right commig_right = false => left
    auto traverse_tree = [&](auto&& self, int v, int root, bool commig_right) -> bool {
        if (!commig_right && g[v].right_next == root) {
            return false;
        }

        if (commig_right) {
            if (g[v].left_next == -1) {
                return true;
            }

            return self(self, g[v].left_next, root, !commig_right);
        } else {
            if (g[v].right_next == -1) {
                return true;
            }

            return self(self, g[v].right_next, root, !commig_right);
        }
    };

    for (int i = 0; i < q; ++i) {
        int idx = lower_bound(p.begin(), p.end(), a[i]) - p.begin();

        int start_node = -1;
        for (int j = idx; j < n; ++j) {
            if ((p[j] - a[i]) % k == d[j]) {
                start_node = j;
                break;
            }
        }

        if (start_node == -1) {
            cout << "YES" << '\n';
        } else {
            cout << (traverse_tree(traverse_tree, start_node, start_node, true) ? "YES" : "NO") << '\n';
        }
    }

}
