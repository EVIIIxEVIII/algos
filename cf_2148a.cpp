#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;

    while (tt--) {
        int x; cin >> x;
        int n; cin >> n;

        cout << (n % 2 == 0 ? 0 : x) << '\n';
    }

    return 0;
}
