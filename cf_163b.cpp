#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n; cin >> n;
    int t; cin >> t;

    vector<char> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];


    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if(s[j] == 'B' && s[j+1] == 'G') {
                swap(s[j], s[j+1]);
                j++;
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << s[i];
    cout << '\n';

    return 0;
}
