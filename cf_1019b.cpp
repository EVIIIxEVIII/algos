#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        int initial = 0;
        char prev = '0';
        for (int i = 0; i < n; ++i) {
            if (prev == s[i]) {
                initial += 1;
            } else {
                prev = s[i];
                initial += 2;
            }
        }

        if (initial - n >= 3) {
            cout << initial - 2 << '\n';
        } else if (initial - n == 2) {
            cout << initial - 1 << '\n';
        } else {
            cout << initial << '\n';
        }
    }
    return 0;
}
