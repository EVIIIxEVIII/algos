#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // idea: first of all I need a more strict condition for a good sequence.
        //
        // idea: if we have an i, such that there exists a j where a[i] < a[j] and i < j, then
        // for all k > j a[k] >= a[j]. Assume we have a[i] < a[j] with i < j, then let a[i] be blue and
        // a[j] be red, assume there exists an index k > j, such that a[k] < a[j], then the color of a[k] must
        // be different from the color of a[j], but that is not possible since a[i] > a[j] > a[k], with i > j > k.
        //
        // conclusion: the longest decreasing subsequence length in a good sequence is at most 2, otherwise it is not
        // possible to color with 2 colors.
        //
        // idea: so the problem becomes: find the number of subsequences in the array a, such that that LDS of the
        // subsequence is <= 2.
        //
        // idea: maybe it would be easier to compute the number of bad subsequences?
        //
        // idea: what if for every pair such that a[i] < a[j] and i < j we would try to find all the ks such
        // that a[i] < a[j] < a[k] and i < j < k? that would allow us to remove all subsequences which contain
        // these 3 values. But how to avoid double counting?
        //
        // idea: all subsequences where LDS == 1 can be computed from the increasing only subsequences of the array
        // idea: what if we form all increasing only subsequences and then for all the pairs a[i] > a[j] we would check
        // the increasing subsequence both a[i] and a[j] appear in.
        // idea: maybe something like dp? dp[i] the number of increasing only subsequences a[i] appears in. Then
        // if we have a[i] > a[j], i < j, we could basically do ans += dp[i] and ans += dp[j]
        //
        // idea: compute the total number of increasing subseq. using the classical dp in O(n^2), then compute the number of
        // subsequences that end at a[i] and that start at a[i] and that would be the number of increasing subsequences a[i]
        // is contained in.

        vector<int> L(n);
        L[0] = 1;
        for (int i = 1; i < n; ++i) {
            L[i] = 1;
            for (int j = i-1; j >= 0; --j) {
                if (a[i] >= a[j]) {
                    L[i] = (L[i] + L[j]) % mod;
                }
            }
        }

        vector<int> R(n);
        R[n-1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            R[i] = 1;

            for (int j = i+1; j < n; ++j) {
                if (a[i] <= a[j]) {
                    R[i] = (R[i] + R[j]) % mod;
                }
            }
        }



    }
    return 0;
}
