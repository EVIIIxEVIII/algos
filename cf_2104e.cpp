#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<string> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
    }


    // for each string in a[i] I need to know what the "best" way in which
    // we can pick a subsequence of characters from s to form a[i], then this would allow to
    // pick the "furthest" new letter to the right, and so on.
    //
    // so this requires some offline stuff.
    //
    // maybe some kind of ridiculous dp[26][n] thing where at dp[26][n] we would store the index
    // where the character c appers next in s?


    // dp[j][i] = s[i + 1] == (char)(j+'a') ? i + 1 : dp[j][i + 1];

    vector<vector<int>> dp(k, vector<int>(n + 1, -1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            dp[j][i] = dp[j][i + 1];
        }
        dp[s[i]-'a'][i] = i;
    }

    for (int i = 0; i < q; ++i) {
        long long ans = 0;
        auto& str = a[i];

        int next = dp[str[0]-'a'][0];

        for (int j = 1; j < (int)str.size(); ++j) {
            if (next == -1) {
                break;
            }

            next = dp[str[j]-'a'][next + 1];
        }

        while (next != -1) {
            int old = next;
            int next_next = next;
            bool bad = false;

            for (int j = 0; j < k; ++j) {
                int p = dp[j][old + 1];

                if (p == -1) {
                    bad = true;
                    break;
                }

                next_next = max(p, next_next);
            }

            ans++;
            if (bad) {
                break;
            }

            next = next_next;
        }

        cout << ans << '\n';
    }
}
