#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        int a; cin >> a;
        int b; cin >> b;

        bool first = b % 2 == n % 2 && a <= b;
        bool second = b % 2 == n % 2 && a % 2 == n % 2;

        cout << (first || second ? "YES" : "NO") << endl;
    }

    return 0;
}
