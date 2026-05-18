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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // first of all, in the end we have to obtain an array of size k if k % 2 == 1 or k - 1 if k % 2 == 0
    // because if there is a palidrome of larger size we can just remove symmetrically the elements s.t the
    // palidrome is of size k or k - 1.
    //
    // second of all there already must be some subsequence of elements of size k such that that subsequence
    // forms a palidrome, because for example something like 1 2 3 4 5 6 with k > 2 is not convertible to a palidrome.
    //
    // third of all the numbers that form that subsequence of elements of size k should be small enough, because we are
    // allowed to remove the greatest element in a window of size k.
    //
    // first of all we can construct a target that we aim for of size k and size k - 1 because both are obtainable.
    // We can take the k/k - 1 smallest numbers from the array and check if there is a subsequence in the array that
    // is made out of these numbers and which is a palidrome, if there is we can just go and delete bigger numbers one
    // by one and obtain that subsequence.
    //
    // so we can just remove the big elements from the array and obtain an array that contains only the k - 1th smallest
    // elements. After that we are allowed to remove the k - 1th element until the size of the array is either k or k - 1.

    if (k == 1) {
        cout << "YES" << '\n';
        return;
    }

    vector<int> s = a;
    sort(s.begin(), s.end());
    vector<int> b;

    int lim = s[k - 2];
    for (int i = 0; i < n; ++i) {
        if (a[i] <= lim) {
            b.push_back(a[i]);
        }
    }

    int l = 0, r = b.size() - 1;
    int del = 0;
    while (l < r) {
        if (b[l] == b[r]) {
            l++;
            r--;
        } else if (b[l] == lim) {
            del++;
            l++;
        } else if (b[r] == lim) {
            del++;
            r--;
        } else {
            cout << "NO" << '\n';
            return;
        }
    }

    if ((int)b.size() - del >= k - 1) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

