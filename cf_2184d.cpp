#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long C[35][35];

    for (int n = 0; n <= 34; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k) {
            C[n][k] = C[n-1][k-1] + C[n-1][k];
        }
    }

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // idea: there is no DP in the Alice choise, even if you could subtract 1 from the
        // even number, that would be strictly worse, because we move the 0 one move forward and set the
        // current bit to 1, which would require one additional operation.
        //
        // idea: now we know that for each number from 1 to n we would need to spend 2 moves on bits that are set to 1
        // and 1 move on bits that are set to 0. So for each number we could compute the number of "moves" it would
        // take to reduce it to 0, and thus count the number where A always looses.
        //
        // idea: O(n) time would probably TE because n <= 10^9, so we need to find a combinatorics solution.
        //
        // idea:
        //  each 1 in the binary representation => 2 moves
        //  each 0 in the binary representation => 1 move
        //
        // idea: we need to find the number of numbers where their binary representation moves sum > k.
        //
        // idea: we can write Score(m) = popcount(m) + (L-1) where L is the length of the number
        // from condition we have popcount(m) + (L-1) > k
        // thus we need to find all the numbers where popcount(m) > k - L + 1
        // we can go from L = 1 to L = d and then count the number of 1s that can be set by doing a
        // L choose i, from i = 0 to i = L and for i > k - L + 1 we add that value to the answer.

        int d = 31 - __builtin_clz(n); // the index of the msb 0 based

        long long ans = 0;

        for (int L = 1; L <= d; ++L) { // d is equal to the length of 2^d - 1
            // here we can't use numbers > 2^d because 2^d is an upper limit
            int r = k - L + 1; // the lower bound from the idea above
            // here the + 1 is because we have popcnt(m) + (L-1) > k, but we can rewrite popcnt(m) as
            // 1 + r where r is the number of 1s in L - 1 bits, so we have (r + 1) > k - L + 1 => r > k - L
            // and r > k - L <=> r >= k - L + 1

            if (r < 0) r = 0; // the case when k < d so even no 1s in the bit string lead to a loss for A

            for (int i = r; i <= L - 1; ++i) { // 1 at the start is forced so we have L - 1 positions for a 1 to be placed
                ans += C[L - 1][i];
            }
        }

        int score_n = d + 1; // for numbers where the length of the binary string > k
        if (score_n > k) {
            ans += 1;
        }

        cout << ans << '\n';

    }
    return 0;
}
