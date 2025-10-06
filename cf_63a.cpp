#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int globx = 0, globy = 0, globz = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int y; cin >> y;
        int z; cin >> z;

        globx += x;
        globy += y;
        globz += z;
    }

    cout << ((globx == 0 && globy == 0 && globz == 0) ? "YES" : "NO") << '\n';

    return 0;
}
