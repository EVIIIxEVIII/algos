#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <= 9; ++i) {
        int new_num = n - i;
        int need = 10;

        if (new_num == 0) {
            need = min(need, 7);
        }

        while (new_num > 0) {
            int d = new_num % 10;
            need = min(need, (7 - d + 10) % 10);
            new_num /= 10;
        }

        need = min(7, need);
        if (need <= i) {
            cout << i << '\n';
            return;
        }
    }
}
