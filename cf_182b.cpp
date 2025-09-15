#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int l = -1, r = -1;
        int z0 = -1, z1 = -1;

        set<int> nums;
        for (int i = 0; i < n ;++i) {
            nums.insert(a[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0 && z0 == -1) z0 = i;
            if (a[i] != i+1 && l == -1 && a[i] != 0) l = i;
        }

        for (int i = n-1; i >= 0; --i) {
            if (a[i] == 0 && z1 == -1) z1 = i;
            if (a[i] != i+1 && r == -1 && a[i] != 0) r = i;
        }

        if (z0 == z1 && nums.find(z0 + 1) == nums.end()) {
            z0 = -1;
            z1 = -1;
        }

        int len1 = (l == r ? 0 : r - l + 1);
        int len2 = (z0 == z1 ? 0 : z1 - z0 + 1);
        int len3 = (z1 != -1 && r != -1) ? max(z1, r) - min(z0, l) + 1 : 0;

        cout << max(max(len1, len2), len3) << '\n';
    }

    return 0;
}

//When calculating the cost of a permutation, you are allowed to sort only one contiguous subsegment (not multiple segments).
