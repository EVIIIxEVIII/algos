#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long s, m;
        cin >> s >> m;

        if (__builtin_ctzll(s) < __builtin_ctzll(m)) {
            cout << -1 << '\n';
            continue;
        }

        // go through every bit of s and if it is set in m then I set add 1 if not I will go
        // to the right and find the first set bit in m to the right of the bit in s and will add
        // 2^(s_i - m_i) to the answer. But the condition asks for the smallest array so I need to
        // find a way to combine these moves. So the size will be the maximum such value for all bits in S.

        // 101000 - s
        // 100001 - m

        //long long ans = 0;
        //int j = 63;
        //long long curr = 0;

        //for (int i = 63; i >= 0; i--) {
        //    if (((s >> i) & 1) == 0) continue;

        //    if (j > i) {
        //        curr = 0;
        //        j = i;
        //    }

        //    while (j >= 0 && !((m >> j) & 1)) {
        //        j--;
        //    }

        //    if (j >= 0) {
        //        curr += 1LL << (i - j);
        //        ans = max(ans, curr);
        //    }
        //}

        //long long ans2 = 0;
        //int times = 0;
        //while (s != 0) {
        //    m += m;

        //    unsigned long long new_s = s & ~m;

        //    if (new_s != s) {
        //        ans2 += times;
        //        s = new_s;
        //    }

        //    times++;
        //}

        //vector<long long> dp(64);
        //dp[0] = m & 1;

        //for (int i = 1; i < 64; ++i) {
        //    if ((m >> i) & 1) {
        //        dp[i] = 1;
        //    } else {
        //        dp[i] = dp[i-1] * 2;

        //        if (i - dp[i-1] >= 0 && dp[i - dp[i-1]] == 1) {
        //            dp[i] = min(dp[i], dp[i-1] + dp[i - dp[i-1]]);
        //        }
        //    }
        //}

        //long long ans = 0;

        //for (int i = 0; i < 64; ++i) {
        //    if ((s >> i) & 1) {
        //        ans += dp[i];
        //    }
        //}

        //long long ans = 0;
        //while (s > 0) {
        //    long long times = s / m;

        //    ans += times;
        //    s -= (m * times);

        //    int msb = 63 - __builtin_clzll(m);
        //    m ^= 1ULL << msb;
        //}

        //cout << ans << '\n';



    }

    return 0;
}
