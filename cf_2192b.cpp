#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ones = 0;
        int zeros = 0;

        vector<int> zs;
        vector<int> os;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                zeros++;
                zs.push_back(i);
            } else {
                ones++;
                os.push_back(i);
            }
        }

        if (ones == 0) {
            cout << 0 << '\n';
            continue;
        }

        if (zeros % 2 != 1 && ones % 2 != 0) {
            cout << -1 << '\n';
            continue;
        }

        if (zeros % 2 == 1) {
            cout << zs.size() << '\n';
            for (size_t i = 0; i < zs.size(); ++i) {
                cout << zs[i] + 1 << ' ';
            }
            cout << '\n';
        } else {
            cout << os.size() << '\n';
            for (size_t i = 0; i < os.size(); ++i) {
                cout << os[i] + 1 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
