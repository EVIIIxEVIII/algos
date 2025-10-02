#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> d(n);
        vector<int> l(n);
        vector<int> r(n);

        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            cin >> r[i];
        }

        vector<int> list;

        int current = 0;
        bool impossible = false;

        for (int i = 0; i < n; ++i) {
            if (d[i] == -1) {
                list.push_back(i);
            } else {
                current += d[i];
            }

            while (current < l[i]) {
                if (list.empty()) {
                    impossible = true;
                    break;
                }

                d[list.back()] = 1;
                current++;
                list.pop_back();
            }

            while(current + list.size() > r[i]) {
                d[list.back()] = 0;
                list.pop_back();
            }

            if (impossible) break;
        }

        if (impossible) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; ++i) cout << d[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
