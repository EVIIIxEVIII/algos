#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {

        // idea: with the -1 and 1 segments its probably possible to estimate a lower bound
        // and an upper bound on a subarray and then all the numbers between the lower bound and upper
        // bound will be present in the sum. Formally, given a subarray [i, j], s.t i < j it contains
        // all the numbers between the maximum subarray sum and the minimum subarray sum of this subarray.
        //
        // idea: maybe it is worth having 3 cases:
        // a. the bottom part sums [0, x)
        // b. the upper part sums (x, n)
        // c. the whole array [0, n)
        //
        // we could do that classical DP on a and b and then think about c somehow.

        int n;
        cin >> n;

        int x_pos = -1;
        int x = -1;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != 1 && a[i] != -1) {
                x_pos = i;
                x = a[i];
            }
        }

        if (x_pos == -1) {
            x_pos = n;
        }

        if (x_pos + 1 == n && x == 0) {
            cout << 1 << '\n';
            cout << 0 << '\n';
            continue;
        }

        int minS = 0;
        int maxS = 0;

        int cminA = 0;
        int cmaxA = 0;

        for (int i = 0; i < x_pos; ++i) {
            cmaxA = max(cmaxA + a[i], a[i]);
            maxS = max(maxS, cmaxA);

            cminA = min(cminA + a[i], a[i]);
            minS = min(minS, cminA);
        }

        if (x_pos == n) {
            cout << (maxS - minS + 1) << '\n';
            for (int i = minS; i <= maxS; ++i) {
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }

        int cminB = 0;
        int cmaxB = 0;

        for (int i = x_pos+1; i < n; ++i) {
            cmaxB = max(cmaxB + a[i], a[i]);
            maxS = max(maxS, cmaxB);

            cminB = min(cminB + a[i], a[i]);
            minS = min(minS, cminB);
        }

        int globMinA = 0;
        int globMaxA = 0;

        if (x_pos != 0) {
            vector<int> suffixA(x_pos);
            suffixA[x_pos - 1] = a[x_pos - 1];

            for (int i = x_pos - 2; i >= 0; --i) {
                suffixA[i] = suffixA[i+1] + a[i];
            }

            for (int s : suffixA) {
                globMaxA = max(globMaxA, s);
                globMinA = min(globMinA, s);
            }
        }

        int globMinB = 0;
        int globMaxB = 0;

        if (x_pos != n-1) {
            vector<int> prefixB(n - x_pos - 1);
            prefixB[0] = a[x_pos + 1];

            for (int i = 1; i < n - x_pos - 1; ++i) {
                prefixB[i] = prefixB[i - 1] + a[i + x_pos + 1];
            }

            for (int s : prefixB) {
                globMaxB = max(globMaxB, s);
                globMinB = min(globMinB, s);
            }
        }

        int globStart = globMinA + globMinB + x;
        int globEnd = globMaxA + globMaxB + x;

        if (min(maxS, globEnd) - max(globStart, minS) + 1 > 0) {
            cout << max(globEnd, maxS) - min(globStart, minS) + 1 << '\n';

            for (int i = min(globStart, minS); i <= max(globEnd, maxS); i++) {
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }

        cout << (maxS - minS + 1) + (globEnd - globStart + 1) << '\n';
        if (x > 0) {
            for (int i = minS; i <= maxS; ++i) {
                cout << i << ' ';
            }

            for (int i = globStart; i <= globEnd; ++i) {
                cout << i << ' ';
            }
        } else {
            for (int i = globStart; i <= globEnd; ++i) {
                cout << i << ' ';
            }

            for (int i = minS; i <= maxS; ++i) {
                cout << i << ' ';
            }
        }

        cout << '\n';
    }
    return 0;
}
