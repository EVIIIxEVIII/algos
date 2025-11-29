#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, y, r; cin >> n >> y >> r;

        cout << min(n, r + y/2) << '\n';
    }
    return 0;
}
