#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        // idea: prefix sum with sliding window?
        // idea: the 1 -1 then prefix sum thing?

        // main idea1: when seeing a problem with "same number of X and Ys" and in the prefix sum
        // in that array we can see all the places where p[i] == p[j] which are all the segments which
        // contain the same number of X as Y.
        // main idea2: if I see a double sum like sum((i+1)(n - y + 1)) try to fix one index and aggregate the other
        // for example sum_{i < y}{(i + 1)*(n - y + 1)} = sum_{y}{n - y + 1} * sum_{i < y}{(i + 1)} which allowed us
        // to aggregate the second part.

        string s;
        cin >> s;

        int n = s.size();
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back((s[i] == '1' ? 1 : -1));
        }

        vector<int> prefix(n + 1);
        prefix[0] = 0;
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }


        unordered_map<long long, long long> pref;
        // this is essential for the first position where prefix[i] == 0, because the first segment from
        // a[0] to a[i] is valid too. So we insert a 0 before the prefix sum so that we can form this initial
        // segment.
        pref[0] = 1;

        long long ans = 0;
        for (int y = 1; y <= n; ++y) {
            ans = (ans + (n - y + 1) * pref[prefix[y]] % mod) % mod;
            pref[prefix[y]] += y + 1;
        }

        cout << ans << '\n';
    }
    return 0;
}
