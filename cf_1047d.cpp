#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> count(n+1, 0);

        for (int i = 0; i < n; ++i) {
            count[a[i]]++;
        }

        bool possible = true;
        for (int i = 1; i <= n; ++i) {
            if (!count[i]) continue;
            if (count[i] % i != 0) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << -1 << '\n';
            continue;
        }

        int current = 1;
        vector<int> numbers(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            if (!count[i]) continue;
            numbers[i] = current;
            current += count[i] / i;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = numbers[a[i]];
            count[a[i]]--;

            if (count[a[i]] != 0 && count[a[i]] % a[i] == 0) {
                numbers[a[i]]++;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}
