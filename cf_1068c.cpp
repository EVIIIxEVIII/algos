#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // key insight: only the nubmers inside a can be in the answer array
    // and then remove all of the numbers that have a diviser inside the array, because there
    // is no need for them
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        set<int> a_set;
        set<int> a_finished;

        for(int i = 0; i < n; ++i) {
            a_set.insert(a[i]);
        }

        int pos = true;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (a_finished.count(a[i])) continue;

            int num = a[i];
            ans.push_back(num);
            a_finished.insert(num);

            num += a[i];
            while (num <= k) {
                if (a_set.count(num)) {
                    a_finished.insert(num);
                    num += a[i];
                } else {
                    pos = false;
                    break;
                }
            }
        }

        if (!pos) {
            cout << "-1" << '\n';
        } else {
            cout << ans.size() << '\n';
            for (int i = 0; i < ans.size(); ++i) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }

    }
    return 0;
}
