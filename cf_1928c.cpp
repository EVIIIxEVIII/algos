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
    int n, x;
    cin >> n >> x;

    // so k < n
    // some kind of divisibility property?
    //
    // for x = 2 there are 2 groups the 1 2 group and the 2 1 group.
    // 1 2 3 4 3 2 1 2 3 4 3 2 1 -> 12 repeats every 6 positions and 21 every 6 positions too,
    // but then I need to check n - x + 1 for divisibility by 6 and n - k - (k - x) = n - 2k + x for divisibility by 6
    // 2k - 2 is the cycle so 2k - 2 | n - x + 1 or 2k - 2 | n + x - 2
    // write 2k - 2 = z and we have z | n - x + 1 or z | n + x - 2

    set<long long> divisors;
    auto add = [&](long long cand) {
        if (cand % 2 == 0) {
            long long k = (cand + 2) / 2;
            if (k >= x && k > 1) {
                divisors.insert(k);
            }
        }
    };

    long long A = n - x;
    for (int i = 1; i * i <= A; ++i) {
        if (A % i == 0) {
            add(i);
            add(A / i);
        }
    }

    long long B = n + x - 2;
    for (int i = 1; i * i <= B; ++i) {
        if (B % i == 0) {
            add(i);
            add(B / i);
        }
    }

    cout << divisors.size() << '\n';
}
