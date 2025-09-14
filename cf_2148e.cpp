#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        int k; cin >> k;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> count(n+1, 0);
        for (int i = 0; i < n; ++i) {
            count[a[i]]++;
        }

        bool cont = false;
        for (int i = 0; i <= n; ++i) {
            if (count[i] % k) {
                cout << 0 << endl;
                cont = true;
                break;
            } else {
                count[i] /= k;
            }
        }
        if(cont) continue;

        long long ans = 0;
        int l = 0;
        vector<int> localCnt(n+1, 0);

        for (int r = 0; r < n; ++r) {
            int x = a[r];
            localCnt[x]++;

            while (localCnt[x] > count[x]) {
                localCnt[a[l]]--;
                l++;
            }

            ans += (r - l + 1);
        }

        cout << ans << endl;
    }

    return 0;
}
