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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // idea: basically a group is a set of elements such that
    // the elements can be reached in a decreasing order by usin a left
    // and right pointer.


    // maybe a group can be formed by regions where we have increasing then
    // decreasing and it ends at and a_i such that a_i < a_{i+1}

    // check the number of regions where we have increasing first then decreasing?

    bool decreasing = false;
    long long ans = 1;

    for (int i = 0; i < n-1; ++i) {
        if (a[i] > a[i+1]) {
            decreasing = true;
        }

        if (a[i] < a[i+1] && decreasing) {
            decreasing = false;
            ans++;
        }
    }

    cout << ans << '\n';
}
