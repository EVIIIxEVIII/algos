#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        int m; cin >> m;

        vector<array<int, 2>> lines(n);
        for (int i = 0; i < n; ++i) {
            cin >> lines[i][0];
            cin >> lines[i][1];
        }

        int prev = 0;
        int prevWall = 0;

        int penalty = 0;

        for (int i = 0; i < n; ++i) {
            if ((lines[i][0] - prev) % 2 == 0 && lines[i][1] != prevWall) {
                penalty++;
                prev = lines[i][0];
                prevWall = lines[i][1];
                continue;
            }

            if ((lines[i][0] - prev) % 2 != 0 && lines[i][1] == prevWall) {
                penalty++;
                prev = lines[i][0];
                prevWall = lines[i][1];
                continue;
            }
        }

        cout << m - penalty << '\n';

    }

    return 0;
}
