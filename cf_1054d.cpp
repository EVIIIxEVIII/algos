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

        long long totalAs = 0;
        long long totalBs = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') totalAs++;
            if (s[i] == 'b') totalBs++;
        }

        long long aCost = 0;
        long long bCost = 0;

        long long aLeft = 0;
        long long bLeft = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                aCost += min((long long)(i - aLeft), (long long)(n - (totalAs - aLeft) - i));
                aLeft++;
            }

            if (s[i] == 'b') {
                bCost += min((long long)(i - bLeft), (long long)(n - (totalBs - bLeft) - i));
                bLeft++;
            }
        }


        cout << min(aCost, bCost) << '\n';
    }
    return 0;
}
