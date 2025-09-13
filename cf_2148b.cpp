#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;

    while (tt--) {
        int n, m, x, y;
        cin >> n;
        cin >> m;
        cin >> x;
        cin >> y;

        vector<int> hor(n);
        vector<int> ver(m);

        for (int i = 0; i < n; ++i) cin >> hor[i];
        for (int i = 0; i < m; ++i) cin >> ver[i];

        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (hor[i] < y) count++;
            else break;
        }

        for (int i = 0; i < m; ++i) {
            if (ver[i] < x) count++;
            else break;
        }

        cout << count << '\n';
    }

    return 0;
}
