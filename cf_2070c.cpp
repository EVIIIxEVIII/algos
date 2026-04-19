#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // if there exists s[i] = 'B' and s[j] = 'B' and between s[i] and s[j] a[i] > a[i+1..j-1] and a[j] > a[i+1..j-1]
    // then it is always strictly better to color that whole region.

    auto check = [&](int x) -> bool {
        string s_check;

        for (int i = 0; i < n; ++i) {
            if (a[i] > x) {
                s_check.push_back(s[i]);
            }
        }

        int blocks = 0;
        for (int i = 0; i < (int)s_check.size(); ++i) {
            if (s_check[i] == 'B' && (i == 0 || s_check[i-1] != 'B')) {
                blocks++;
            }
        }

        if (blocks > k) {
            return false;
        }
        return true;
    };

    // FFTTT
    int l = 0, r = *max_element(a.begin(), a.end());
    while (l < r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }


    cout << l << '\n';
}
