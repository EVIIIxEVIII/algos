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
        // and push all the numbers greater than it to the right. All the numbers
        // pushed to the right should be increased by 1.

        vector<int> suffix(n);
        suffix[n-1] = a[n-1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = min(a[i], suffix[i+1]);
        }

        vector<int> ans;
        multiset<int> pushed;
        bool switched = false;

        for (int i = 0; i < n; ++i) {
            if (switched) {
                pushed.insert(a[i] + 1);
                continue;
            }

            if (a[i] == suffix[i]) {
                if (pushed.empty() || a[i] <= *pushed.begin()) {
                    ans.push_back(a[i]);
                } else {
                    switched = true;
                    pushed.insert(a[i] + 1);
                }
            } else {
                pushed.insert(a[i] + 1);
            }
        }

        for (size_t i = 0; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
        }

        for (int x : pushed) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}
