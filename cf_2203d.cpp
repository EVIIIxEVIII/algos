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
    int n, m;
    cin >> n >> m;

    unordered_map<int,int> a;
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        a[num]++;
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // let's divide numbers from b in 3 categories:
    // 1. there exists a number a[i] s.t a[i] | b[i] and there exists a number a[j] s.t a[j] doesn't divide b[i]
    // 2. for all 1 <= i <= n, a[i] divides b[i]
    // 3. for all 1 <= i <= n, a[i] doesn't divide b[i]
    //
    // So Bob and Alice should firstly try to use numbers from category 1. and then use numbers from their own category.
    // denote # of numbers from 1. as c1, then for Alice we have (c1 + 1) / 2 and for Bob c1 / 2.
    // if (c1 + 1) / 2 + c2 > c1/2 + c3 Alice wins, otherwise Bob wins.

    int c1 = 0;
    int c2 = 0;
    int c3 = 0;

    vector<int> cnt(n + m + 1, 0);

    for (int d = 1; d <= n + m; ++d) {
        if (a[d] == 0) {
            continue;
        }

        for (int x = d; x <= m + n; x+=d) {
            cnt[x] += a[d];
        }
    }


    for (int i = 0; i < m; ++i) {
        int count = cnt[b[i]];
        if (count == 0) {
            c3++;
        } else if (count == n) {
            c2++;
        } else {
            c1++;
        }
    }

    if ((c1 + 1) / 2 + c2 > c1/2 + c3) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
    }
}
