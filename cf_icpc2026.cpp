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

        std::priority_queue<int> a;
        std::priority_queue<int> b;

        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.push(x);
        }

        for (int i = 0; i < m; ++i) {
            int y; cin >> y;
            b.push(y);
        }

        bool alice = true;
        while (!a.empty() && !b.empty()) {
            if (alice) {
                int al = a.top();
                int bo = b.top();
                b.pop();

                int res = bo - al;
                if (res > 0) {
                    b.push(res);
                }
            } else {
                int al = a.top();
                int bo = b.top();
                a.pop();

                int res = al - bo;
                if (res > 0) {
                    a.push(res);
                }
            }

            alice = !alice;
        }

        cout << (a.empty() ? "Bob" : "Alice") << '\n';
    }

    return 0;
}
