#include <bits/stdc++.h>
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

        int seqLen = 0;
        bool ok = true;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (seqLen % 2 && seqLen < 5) {
                    ok =  false;
                }

                seqLen = 0;
            } else {
                seqLen++;
            }
        }

        if (!ok) {
            cout << "NO" << '\n';
            continue;
        }

        string out;
        out.resize(n);





    }
    return 0;
}
