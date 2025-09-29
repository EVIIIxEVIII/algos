#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        string s;
        s.resize(n);
        for (int i = 0; i < n; ++i) cin >> s[i];

        set<int> a;

        for (int i = 0; i < m; ++i) {
            int num; cin >> num;
            a.insert(num);
        }

        int cur = 1;

        for (int i = 0; i < n; ++i) {
            cur++;

            if (s[i] == 'B') {
                while (a.count(cur)) cur++;
            }

            a.insert(cur);

            if (s[i] == 'B') {
                while (a.count(cur)) cur++;
            }
        }

        cout << a.size() << '\n';
        for (auto& x: a) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
