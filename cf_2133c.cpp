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
    // just find the root of the dag in 2n queries?
    int n; cin >> n;


    // ? x k s1 s2 s3 ... sk - ask
    // cout.flush(); - after ask
    // ! x v1 v2 ... vk - answer

    // we can firstly ask n queries where for each node we ask for the longest path starting
    // from that node n and going through all the other nodes except that node, i.e S \ n where S
    // is the set of all the nodes.
    // after we did that we have a clear picture of the longest path we can get and so the first node
    // in our answer is the node which got the maximum answer.
    //
    // for the next node in the sequence we would like to pick the node which got a path of lenght max - 1
    // but we don't know if it is connected to the first node so we need to ask a question to understand
    // which node from the set of nodes which had answer max - 1 is connected to the one which got max.
    // We can do it probably by exclusion, i.e say node 1 got the max and node 2 and 3 got max - 1, we
    // ask ? 1 k S \ {2} and ? 1 k S \ {3} if we still get max after removing say 2, it means that 3 is the next node.

    vector<pair<int,int>> paths(n+1);
    for (int i = 1; i <= n; ++i) {
        cout << "? " << i << ' ' << n << ' ';
        for (int j = 1; j <= n; ++j) {
            cout << j << ' ';
        }
        cout << '\n';
        cout.flush();

        cin >> paths[i].first;
        paths[i].second = i;
    }

    sort(paths.begin(), paths.end(), greater<pair<int,int>>());

    vector<int> ans;
    int root = paths[0].second;
    int root_path = paths[0].first;
    ans.push_back(root);

    int cur_len = root_path;
    int cur_node = root;

    while (cur_len > 1) {
        int target = cur_len - 1;

        set<int> cand;
        for (int i = 0; i < n; ++i) {
            if (paths[i].first == target) {
                cand.insert(paths[i].second);
            }
        }

        for (int c : cand) {
            cout << "? " << cur_node << ' ' << n - cand.size() + 1 << ' ';
            for (int i = 1; i <= n; ++i) {
                if (cand.contains(i)) continue;
                cout << i << ' ';
            }
            cout << c << '\n';
            cout.flush();

            int new_path; cin >> new_path;
            if (new_path == cur_len) {
                ans.push_back(c);
                cur_node = c;
                cur_len = target;
                break;
            }
        }
    }

    cout << "! " << ans.size() << ' ';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    cout.flush();
}
