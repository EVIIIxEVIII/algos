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

        vector<int> suffix(n);
        suffix[n-1] = a[n-1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i+1], a[i]);
        }

        bool switched = false;
        vector<int> unchanged;
        multiset<int> pushed;

        for (int i = 0; i < n; ++i) {
            if (switched) {
                pushed.insert(a[i] + 1);
                continue;
            }

            if (a[i] == suffix[i]) {
                if (pushed.empty() || *pushed.begin() >= a[i]) {
                    unchanged.push_back(a[i]);
                } else {
                    pushed.insert(a[i] + 1);
                    switched = true;
                }
            } else {
                pushed.insert(a[i] + 1);
            }
        }

        for (int x : unchanged) {
            cout << x << ' ';
        }

        for (int x : pushed) {
            cout << x << ' ';
        }

        cout << '\n';
    }
    return 0;
}
