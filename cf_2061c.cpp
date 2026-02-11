#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {

        // idea: use a 2 state dp where:
        // - dp[0][i] number of configurations so far where i is a liar
        // - dp[1][i] number of configurations so far where i is not a liar
        //
        // idea: for each dp[1] go back and compare a[i] with all the a[j] such that j < i
        // if a[j] > a[i] then this mf must be a liar from a[i] perspective otherwise it can be either
        // a liar or not.
        //
    }
    return 0;
}
