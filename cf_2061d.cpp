#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        // idea: by definition sum(a) == sum(b) and for all numbers b[i]
        // b[i] >= a[j], for all a[
        //
        // idea:

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }

        for (int i = 0; i < m; ++i) {
            cin>>b[i];
        }

        multiset<int> need(a.begin(), a.end());
        priority_queue<int> b_items;
        for (int i = 0; i < m; ++i) {
            b_items.push(b[i]);
        }

        for (int splits = 0; splits < n - m && !b_items.empty();) {
            int c = b_items.top();
            b_items.pop();

            auto it = need.find(c);
            if (it != need.end()) {
                need.erase(it);
            } else {
                int x1 = (c + 1) / 2;
                int x2 = c / 2;

                b_items.push(x1);
                b_items.push(x2);
                splits++;
            }
        }

        while(!b_items.empty()) {
            int c = b_items.top();

            auto it = need.find(c);
            if (it != need.end()) {
                need.erase(it);
                b_items.pop();
            } else {
                break;
            }
        }

        if (b_items.empty() && need.empty()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
