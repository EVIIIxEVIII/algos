#include <algorithm>
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

    int t = n + m + 1;
    vector<int> a(t);
    vector<int> b(t);

    for (int i = 0; i < t; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < t; ++i) {
        cin >> b[i];
    }

    // so for some person i, the picks before them stay constant, so we can compute a prefix sum.
    // the last person n + m will be a forced move, because they are last.
    // if i person i is a programmer we need to find the closest person to the right such that a[i] > b[i], if
    // such a person doesn't exist person j becomes the last candidate n + m + 1, call that person j.
    // Then for person i we have:
    // prefix[i] + suffix[i] - a[i] - (j == n + m + 1 ? a[n + m + 1] : a[j] - b[j] + b[n + m + 1])

    long long total = 0;
    vector<bool> is_prog(t, false);

    int progs = n, tests = m;
    for (int i = 0; i < t - 1; ++i) {
        if ((a[i] > b[i] && progs > 0) || tests == 0) {
            is_prog[i] = true;
            progs--;
            total += a[i];
        } else if ((a[i] < b[i] && tests > 0) || progs == 0) {
            is_prog[i] = false;
            tests--;
            total += b[i];
        }
    }

    pair<long long,int> best_prog = { a[t-1], t-1 };
    pair<long long, int> best_test = { b[t-1], t-1 };

    vector<long long> ans_arr;
    for (int i = t - 1; i >= 0; --i) {
        if (a[i] > b[i]) {
            if (is_prog[i]) {
                long long ans = total - a[i];

                if (best_prog.second == t-1) {
                    ans += best_prog.first;
                } else {
                    ans += best_prog.first - b[best_prog.second] + b[t-1];
                }
                ans_arr.push_back(ans);
            } else {
                best_prog = { a[i], i };
                ans_arr.push_back(total - b[i] + b[t-1]);
            }
        } else {
            if (!is_prog[i]) {
                long long ans = total - b[i];

                if (best_test.second == t-1) {
                    ans += best_test.first;
                } else {
                    ans += best_test.first - a[best_test.second] + a[t-1];
                }
                ans_arr.push_back(ans);
            } else {
                best_test = { b[i], i };
                ans_arr.push_back(total - a[i] + a[t-1]);
            }
        }
    }

    reverse(ans_arr.begin(), ans_arr.end());
    for (long long val : ans_arr) {
        cout << val << ' ';
    }
    cout << '\n';
}
