#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long al = 0;
    long long bo = 0;

    sort(a.begin(), a.end());
    vector<long long> odds;
    for (int i = 0; i < n;) {
        int cnt = 0;
        int j = i;

        while (j < n && a[i] == a[j]) {
            cnt++;
            j++;
        }

        if (a[i] % 2) {
            odds.push_back(cnt);
        }

        al += a[i] / 2 * cnt;
        bo += a[i] / 2 * cnt;

        i = j;
    }
    sort(odds.begin(), odds.end(), greater<long long>());

    for (int i = 0; i < (int)odds.size(); ++i) {
        if (i % 2 == 0) {
            al += odds[i];
        } else {
            bo += odds[i];
        }
    }

    cout << al << ' ' << bo << '\n';
}
