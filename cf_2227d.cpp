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
    int n;
    cin >> n;

    vector<int> a(2*n);
    int first_z = -1;
    int second_z = -1;

    for (int i = 0; i < 2*n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            if (first_z == -1) {
                first_z = i;
            } else {
                second_z = i;
            }
        }
    }

    auto get_mex = [&](vector<int>& vec) {
        sort(vec.begin(), vec.end());

        int mex = 0;
        for (int x : vec) {
            if (x == mex) {
                mex++;
            } else if (x > mex) break;
        }
        return mex;
    };

    int l = first_z;
    int r = second_z;

    bool ok = true;
    vector<int> have;
    while (l <= r) {
        if (a[l] == a[r]) {
            have.push_back(a[l]);
        } else {
            ok = false;
            break;
        }
        l++;
        r--;
    }

    int ans_both = 1;
    if (ok) {
        l = first_z-1;
        r = second_z+1;
        while (l >= 0 && r < 2*n) {
            if (a[l] == a[r]) {
                have.push_back(a[l]);
            } else break;
            l--;
            r++;
        }

        ans_both = get_mex(have);
    }

    vector<int> have_left;
    have_left.push_back(0);
    l = first_z - 1;
    r = first_z + 1;
    while (l >= 0 && r < 2*n) {
        if (a[l] == a[r]) {
            have_left.push_back(a[r]);
        } else break;
        l--;
        r++;
    }
    int ans_left = get_mex(have_left);

    vector<int> have_right;
    have_right.push_back(0);
    l = second_z - 1;
    r = second_z + 1;
    while (l >= 0 && r < 2*n) {
        if (a[l] == a[r]) {
            have_right.push_back(a[r]);
        } else break;

        l--;
        r++;
    }

    int ans_right = get_mex(have_right);
    cout << max({ ans_both, ans_left, ans_right }) << '\n';
}
