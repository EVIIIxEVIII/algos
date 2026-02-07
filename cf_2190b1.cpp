#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;


        vector<int> prefix(n);
        prefix[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') {
                prefix[i] = prefix[i-1] + 1;
            } else {
                prefix[i] = prefix[i-1] - 1;
            }
        }

        vector<int> suffix(n);
        suffix[n-1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i+1] + (s[i] == ')');
        }

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')') {
                if (prefix[i] + 2 <= suffix[i] - 1) {
                    ans = n - 2;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
