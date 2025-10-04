#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;

        long long rowDistance = 0;
        long long colDistance = 0;

        if (rk > rd) {
            rowDistance = n - rd;
        } else if (rk < rd) {
            rowDistance = rd;
        }

        if (ck > cd) {
            colDistance = n - cd;
        } else if (ck < cd) {
            colDistance = cd;
        }


        cout << max(rowDistance, colDistance) << '\n';
    }
    return 0;
}
