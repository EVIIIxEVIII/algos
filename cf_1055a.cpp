#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;


        set<int> a;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.insert(x);
        }

        int ans = 0;
        for (int x : a) {
            ans++;
        }

        cout << (ans-1)*2 + 1 << '\n';
    }
    return 0;
}
