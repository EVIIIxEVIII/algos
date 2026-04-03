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
    string s;
    string t;

    cin >> s;
    cin >> t;

    array<int, 26> count;
    count.fill(0);
    for (char c : t) {
        count[c - 97]++;
    }

    vector<string> substrings;
    char max_char = s[0];
    string temp;

    for (char c : s) {
        if (count[c - 97] != 0) {
            count[c - 97]--;
        } else {
            cout << "Impossible" << '\n';
            return;
        }

        if (max_char < c) {
            substrings.push_back(temp);
            temp = c;
            max_char = c;
        } else {
            temp.push_back(c);
        }
    }

    if (!temp.empty()) {
        substrings.push_back(temp);
    }


    int j = 0;
    for (int i = 0; i < 26; ++i) {
        if (j < substrings.size() && substrings[j][0] == char(i+97)) {
            cout << substrings[j];
            j++;
        }

        for (int k = 0; k < count[i]; ++k) {
            cout << char(i+97);
        }

    }

    cout << '\n';
}
