#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // the main take away from this problem is that if you have a
        // problem where you are asked if you can create a tree, then you
        // should refreme the question to: can you contruct a spanning tree first, because
        // if you can contruct a connected spanning tree, you can remove some edges
        // and obtain a tree

        // So the idea in this problem is that if there exists a split in the array such that all elements
        // to the left of the split are greater than all elements to the right of the split, then the answer is false
        // because the graph is not connected. This is because if there exists a split [a_1, ..., a_m] [a_m+1, ..., a_n]
        // such that min(a_1, ..., a_m) > max(a_m+1, ..., a_n), the there is no possible connection between elements in the
        // subarray a_1, ..., a_m with elements in the subarray a_m+1, ..., a_n. If there a connected graph, then we can form
        // a tree, because the graph will be a spanning tree.

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = a[0];
        suffix[n-1] = a[n-1];

        for (int i = 1; i < n; ++i) {
            prefix[i] = min(a[i], prefix[i-1]);
        }

        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = max(a[i], suffix[i+1]);
        }

        bool ans = true;
        for (int i = 0; i < n-1; ++i) {
            if (prefix[i] > suffix[i+1]) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
