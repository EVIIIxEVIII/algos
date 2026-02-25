#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, w, d;
        cin >> n >> w >> d;

        int max_tower = min(d / w + 1, n);

        cout << (n / max_tower) + (n % max_tower != 0) << '\n';
    }

    return 0;
}
