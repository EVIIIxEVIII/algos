#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        string s;
        s.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        vector<array<int, 2>> blocks;

        int lastBlock = 0;
        bool inBlock = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0' && !inBlock) {
                inBlock = true;
                blocks.push_back({i, i});
            }

            if (s[i] == '1' && inBlock) {
                inBlock = false;
                blocks[lastBlock][1] = i;
                lastBlock++;
            }
        }

        if (inBlock) {
            blocks[lastBlock][1] = n;
        }

        bool ans = true;
        vector<int> out(n, 0);

        int curr = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                out[i] = i+1;
            }
        }

        for (int i = 0; i < blocks.size(); ++i) {
            if (blocks[i][1] - blocks[i][0] == 1) {
                ans = false;
                break;
            }

            for (int j = blocks[i][0]; j < blocks[i][1]-1; ++j) {
                out[j] = j+2;
            }

            out[blocks[i][1]-1] = blocks[i][0]+1;
        }

        if (ans) {
            cout << "YES" << '\n';
            for(int i = 0; i < n; ++i) cout << out[i] << ' ';
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
