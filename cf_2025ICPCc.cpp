#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string s;
    std::string t;

    cin >> s;
    cin >> t;

    // main idea:
    // when there are two interconnected degrees of freedom (in this case the suffix and prefix which
    // cannot be greedily and independently optimized on their own) try to list other degrees of freedom.
    // In this case you cannot minimize on the suffix, you cannot minimize only the prefix, you cannot minimize both
    // of them because that would be O(n^2), but you know that the overlap will be one character. So the remaning degree
    // of freedom are the characters. So you can loop through the characters.

    std::array<int, 256> map;
    map.fill(0);

    for (char c = 'a'; c <= 'z'; ++c) {
        int prefixEnd = -1;
        int suffixStart = -1;

        for (int j = 1; j < s.size(); ++j) {
            if (s[j] == c) {
                prefixEnd = j;
                break;
            }
        }

        for (int j = t.size() - 2; j >= 0; --j) {
            if (t[j] == c) {
                suffixStart = j;
                break;
            }
        }

        if (prefixEnd != -1 && suffixStart != -1) {
            map[c] = prefixEnd + t.size() - suffixStart;
        }
    }

    signed char minChar = -1;
    int minLen = INT_MAX;

    for (char i = 'a'; i <= 'z'; ++i) {
        if (map[i] && map[i] < minLen) {
            minChar = i;
            minLen = map[i];
        }
    }

    if (minChar == -1) {
        cout << -1 << '\n';
        return 0;
    }

    cout << s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (minChar == s[i]) {
            break;
        } else {
            cout << s[i];
        }
    }

    int suffixStart = -1;
    for (int i = t.size() - 2; i >= 0; --i) {
        if (minChar == t[i]) {
            suffixStart = i;
            break;
        }
    }

    for (int i = suffixStart; i < t.size(); ++i) {
        cout << t[i];
    }

    cout << '\n';

    return 0;
}
