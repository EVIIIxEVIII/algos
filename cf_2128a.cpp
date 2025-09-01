#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >>n;
        int c; cin >>c;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int s = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= c) s = i;
            else break;
        }

        int j = 0;
        for (int i = s; i >= 0; --i) {
            if ((1LL << j) * a[i] <= c) {
                j++;
            }
        }

        cout << n - j << '\n';
    }

    return 0;
}
