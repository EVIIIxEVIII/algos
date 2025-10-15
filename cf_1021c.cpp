#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        bool ans = false;
        bool started = false;
        int seq = 0;
        int seqN = -1;

        for (int i = 0; i < n; ++i) {
            if (seqN == a[i]) {
                seq++;
                if (seq == 4 || (started && seq >= 2)) {
                    ans = true;
                    break;
                }
            } else if (seqN+1 == a[i]) {
                if (seq >= 2) {
                    started = true;
                }
                seqN++;
                seq = 1;
            } else {
                seq = 1;
                seqN = a[i];
                started = false;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
