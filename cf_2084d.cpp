#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        // idea: it is probably always better to perform this operation m times, because
        // mex cannot be increased by removing elements from an array anyways. So now
        // we f(b) can be defined as removing k * m elements such that mex is minimized.
        //
        // idea: so we need to construct an array a such that after removing k * m elements in any
        // ways possible described by the function there will still be n - k * m elements such that
        // their mex is maximized.
        //
        // idea: if we have some k, and we place for example 0s, such that # of 0 > m and i - j > k for all i > j, where
        // a[i] == a[j] == 0 then we would have at least mex = 1.
        //
        // idea: let's denote all the numbers in the remaning seqeunce b_i, then for each b_i the number of b_i occurences
        // in a should be > m and the distance between any two such b_i must be at least k

        // idea: we need to find the first number x such that floor(n / x) > m, using binary search, then we would be able to just have
        // m + 1 seqeunces of these numbers in the array a.
        // in the binary search we have a ttttttffffff situation, so we need to find the last x such that floor(n / x) > m, this
        // is a m = (l + r + 1) / 2, l = m, r = m - 1; type of binary search

        //vector<int> ans(n);

        int l = 1;
        int r = n;

        while (l < r) {
            int mid = (l + r + 1) / 2;
            if ((n / mid) > m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        int times = 0;


        while(times < n) {
            for (int i = 0; i < (l < k ? k : l) && times < n; ++i) {
                cout << i << ' ';
                times++;
            }
        }

        cout << '\n';
    }
    return 0;
}
