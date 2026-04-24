#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    // there are 2 types of intervals which matter:
    // - intervals of the form a[i] > b[i] intersection intervals of the form a[j] < b[j]
    // - a[i] > a[j] and b[j] < b[i] of the same type

    // nvm they all go to the right, misread...

    sort(a.begin(), a.end(), [&](auto a, auto b) {
        return a.second < b.second;
    });

    long long cnt = 0;
    tree<int, null_type, less<int>, rb_tree_tag,
     tree_order_statistics_node_update> os;

    for (int i = 0; i < n; ++i) {
        cnt += os.size() - os.order_of_key(a[i].first + 1);
        os.insert(a[i].first);
    }

    cout << cnt << '\n';
}
