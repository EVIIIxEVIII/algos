#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;

        vector<int> a(n);
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) cin >> a[i];

        bool ans = false;
        for (int i = 0; i < n; ++i) {
            if (m[a[i]] != 0) {
                ans = true;
                break;
            } else m[a[i]]++;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
