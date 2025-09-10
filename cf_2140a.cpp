#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;

        vector<char> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int wrong = 0;
        int ones = 0;
        int zeros = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') ones++;
            else zeros++;
        }

        for (int i = 0; i < zeros; ++i) {
            if (a[i] == '1') wrong++;
        }

        cout << wrong << '\n';
    }

    return 0;
}
