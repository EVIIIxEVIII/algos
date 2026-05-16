
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    vector<long long> seg(4*n);
    auto build = [&] (auto&& self, int v, int l, int r) -> void {
        if (l == r) {
            seg[v] = a[l];
            return;
        }

        int m = l + (r - l) / 2;

        self(self, v*2, l, m);
        self(self, v*2 + 1, m + 1, r);

        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    };

    auto get_impl = [&] (auto&& self, int v, int tl, int tr, int l, int r) -> long long {
        if (l > r) return 0;

        if (l == tl && r == tr) {
            return seg[v];
        }

        int tm = tl + (tr - tl) / 2;

        return
            self(self, v * 2, tl, tm, l, min(r, tm)) +
            self(self, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    };

    auto get = [&] (int l, int r) {
        return get_impl(get_impl, 1, 0, n - 1, l, r);
    };





}
