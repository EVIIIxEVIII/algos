#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;


        bool ans = true;
        for (int i = 0; i < 32; ++i) {
            int setX = (x >> i) & 1;
            int setY = (y >> i) & 1;
            int setZ = (z >> i) & 1;

            int val = setX + setY + setZ;
            if (val == 2) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
