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


    }
    return 0;
}
