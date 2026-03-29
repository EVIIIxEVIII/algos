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

    vector<string> a;
    a.reserve(k);

    for (int i = 0; i < k; ++i) {
        string s; cin >> s;
        a.push_back(s);
    }

    vector<int> candidates;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            candidates.push_back(i);
            if (i != n/i) {
                candidates.push_back(n / i);
            }
        }
    }
    sort(candidates.begin(), candidates.end());

    vector<set<int>> slots(n);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < k; ++i) {
            slots[j].insert(a[i][j]);
        }
    }

    auto check_letter = [&](char letter, int i, int win) -> bool {
        for (int j = i; j < n; j += win) {
            if (!slots[j].contains(letter)) {
                return false;
            }
        }
        return true;
    };

    auto check = [&](int win) -> optional<string> {
        string ans;
        for (int i = 0; i < win; ++i) {
            bool any = false;

            for (char letter : slots[i]) {
                bool valid = check_letter(letter, i, win);
                if (valid) {
                    ans.push_back(letter);
                    any = true;
                    break;
                }
            }

            if (!any) {
                return nullopt;
            }
        }

        return ans;
    };

    for (int c : candidates) {
        auto ans = check(c);
        if (ans.has_value()) {
            for (int i = 0; i < n/c; ++i) {
                cout << ans.value();
            }
            cout << '\n';
            return;
        }
    }
}
