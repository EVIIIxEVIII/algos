#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // idea: sort the array ascending using these ops?
        // 3, 5, 1, 9 -> 1, 9, 4, 6 -> 1, 4, 6, 10

        // idea: pick the global smallest number, then push all the
        // numbers before it to the right, then go to the next smallest number
        // an push all the numbers greater than it to the right. All the numbers
        // pushed to the right should be increased by 1.

    }
    return 0;
}
