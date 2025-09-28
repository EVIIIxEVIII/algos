#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        string s;
        s.resize(n);
        for (int i = 0; i < n; ++i) cin >> s[i];

        vector<int> a(n);
        for (int i = 0; i < m; ++i) cin >> a[i];

        int nextWhite = 0;

        for (int i = 0; i < m; ++i) {
            if (a[i] != i+1) {
                nextWhite = i+1;
            }
        }

        int current = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                current++;
            } else {

            }
        }



    }
    return 0;
}
