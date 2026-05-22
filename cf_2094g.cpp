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
    int q;
    cin >> q;

    long long current = 0;
    long long current_rev = 0;
    long long sum = 0;
    int size = 0;

    deque<int> els;
    bool is_rev = false;

    for (int i = 0; i < q; ++i) {
        int s;
        cin >> s;

        long long k;
        if (s == 3) {
            cin >> k;
        }

        if (s == 3) {
            size++;
            current += size * k;
            current_rev += sum + k;

            sum += k;
            if (!is_rev) {
                els.push_back(k);
            } else {
                els.push_front(k);
            }

        } else if (s == 2)  {
            swap(current_rev, current);
            is_rev = !is_rev;

        } else if (s == 1) {
            if (is_rev) {
                long long last = els.front();
                els.pop_front();
                els.push_back(last);

                current = current + sum - last * size * 1LL;
                current_rev = (current_rev - sum) + last * size * 1LL;
            } else {
                long long last = els.back();
                els.pop_back();
                els.push_front(last);

                current = current + sum - last * size * 1LL;
                current_rev = (current_rev - sum) + last * size * 1LL;
            }
        }

        cout << current << '\n';
    }

    // for the first operations we only need the know the value of the current last element of the array
    // and then we would need to add the prefix sum from [0, n - 2] and decrease by a[n-1] * (n - 1)
    //
    // we can keep the score for both the reversed array and the non reversed version. For instance, when adding a
    // new element we can have long long ok_arr += size * k and then long long rev_arr += rev_arr + k; and then
    // we would need a is_currenly_reversed flag to decide which of the two to output.
}
