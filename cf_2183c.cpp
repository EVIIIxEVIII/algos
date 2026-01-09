#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int maxRight = n - k;
        int maxLeft = k - 1;

        // main idea: sometimes it is useful to see what constrains apply to the best
        // greedy approach and then work backwards by trying to fit the variables.
        // In this case the idea was to figure out that the l + r + max(l, r) - 1 <= m
        // for the greedy solution where you cache soldiers in in the first moves then dispatch to
        // the right and then dispatch the accumulated ones to the left. And then because you have constrains
        // on both l and r, you can easily increase them one by one.

        int l = 0;
        int r = 0;

        while (true) {
            bool op = false;
            if (l < maxLeft && l + r + max(l+1, r) <= m) {
                l++;
                op = true;
            }
            if (r < maxRight && l + r + max(l, r+1) <= m) {
                r++;
                op = true;
            }

            if (!op) break;
        }

        cout << r + l + 1 << '\n';
    }

    return 0;
}
