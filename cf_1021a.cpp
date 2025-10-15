#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;

        vector<int> map(10, 0);
        for (int i = 0; i < s.size(); ++i) {
            map[s[i] - '0']++;
        }

        vector<int> ans(10);

        for (int i = 0; i < 10; ++i) {
            for (int j = 9 - i; j < 10; ++j) {
                if (map[j] != 0) {
                    ans[i] = j;
                    map[j]--;
                    break;
                }
            }
        }

        for (int i = 0; i < 10; ++i) cout << ans[i];
        cout << '\n';
    }
    return 0;
}
