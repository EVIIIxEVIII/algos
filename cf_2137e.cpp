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
    // idea: before the MEX point you a_i for the sum after the MEX point
    // use the MEX of the whole array.

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int mex = -1;
    int c1 = -1;
    int c2 = -1;
    int count = 0;

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1] || a[i-1] + 1 != a[i]) {
            break;
        }
        ans += a[i];
    }

    for (int i = 1; i < n;) {
        if (a[i] != a[i-1] && a[i] != a[i-1] + 1) {
            count += n - i;
            mex = a[i-1] + 1;
            break;
        }

        if (a[i] == a[i-1]) {
            count++;
        } else {
            i++; continue;
        }

        while (i < n && a[i] == a[i-1]) {
            if (c1 == -1) {
                c1 = a[i];
            } else if (c2 == -1) {
                c2 = a[i];
            }

            count++;
            i++;
        }
    }

    if (mex == -1) {
        mex = a.back() + 1;
    }

    if (a[0] != 0) {
        mex = 0;
        ans = 0;
        count = n;
        c1 = -1;
        c2 = -1;
    }

    if (count == 1) {
        cout << ans + mex << '\n';
        return;
    }

    if (c1 == -1 && c2 == -1) {
        ans += (count * (mex + (k % 2 == 0)));
    } else if (c1 != -1 && c2 != -1) {
        if (k == 1) {
            ans += count * mex;
        } else {
            k--;
            ans += (count * (k % 2 ? c2 : c1));
        }
    } else if (c1 != -1) {
        ans += (count * (k % 2 ? mex : c1));
    }

    cout << ans << '\n';
}
