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
    string n;
    cin >> n;

    long long sum = 0;
    long long twos = 0;
    long long threes = 0;

    for (char c : n) {
        sum += c - '0';

        if (c == '2') {
            twos++;
        } else if (c == '3') {
            threes++;
        }
    }

    // Let N = 100a + 10b + c
    // Let S = a + b + c
    //
    // N - S = 99a + 9b = 9(11a + b) => N - S equiv 0 (mod 9) <=>
    // N equiv S (mod 9). So the sum of digits of a number defines
    // its divisibility by 9.

    for (int a = 0; a <= min(twos, 9LL); ++a) {
        for (int b = 0; b <= min(threes, 9LL); ++b) {
            if ((sum + 2 * a + 6 * b) % 9 == 0) {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}
