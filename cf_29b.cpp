#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> odds;
        vector<int> evens;

        if (n == 2) {
            cout << "1 2 1 2\n";
            continue;
        } else if (n == 1) {
            cout << "1 1\n";
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            if (i % 2) {
                odds.push_back(i);
            } else {
                evens.push_back(i);
            }
        }

        cout << 1 << ' ';

        for (int i = odds.size()-2; i > 0; --i) {
            cout << odds[i] << ' ';
        }

        if (n % 2 == 0) {
            cout << 1 << ' ';
            cout << odds.back() << ' ';
        } else {
            cout << odds.back() << ' ';
            cout << 1 << ' ';
        }

        for (int i = 1; i < odds.size()-1; ++i) {
            cout << odds[i] << ' ';
        }

        for (int i = evens.size()-1; i >= 0; --i) {
            cout << evens[i] << ' ';
        }

        cout << odds.back() << ' ';

        for (int i = 0; i < evens.size(); ++i) {
            cout << evens[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}
