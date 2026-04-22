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
    int n;
    cin >> n;

    string s;
    cin >> s;

    // probably bruteforceable for all divisors of n, something like sqrt(n)*n?

    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    for (int d : divisors) {
        unordered_map<string, int> seen;

        for (int i = 0; i < n; i += d) {
            string temp;
            for (int j = i; j < i+d; ++j) {
                temp.push_back(s[j]);
            }

            seen[temp]++;
        }

        if (seen.size() <= 2) {
            int min_count = INT_MAX;
            string str1;
            string str2;

            for (auto [k, v] : seen) {
                min_count = min(min_count, v);
                if (str1.empty()) str1 = k;
                else str2 = k;
            }

            if (seen.size() == 2 && min_count == 1) {
                int diff = 0;
                for (int i = 0; i < d; ++i) {
                    if (str1[i] != str2[i]) {
                        diff++;
                    }
                }
                if (diff == 1) {
                    cout << d << '\n';
                    return;
                }
            } else if (seen.size() == 1) {
                cout << d << '\n';
                return;
            }
        }
    }
}
