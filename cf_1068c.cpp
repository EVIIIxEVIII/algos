#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // key insight: only the nubmers inside a can be in the answer array
    // and then remove all of the numbers that have a diviser inside the array, because there
    // is no need for them
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        static long long primes[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53};

        sort(a.begin(), a.end());

        set<int> nums;
        for (int i = 0; i < n; ++i) {
            nums.insert(a[i]);
        }

        for (int i = 0; i < 16; ++i) {
            int n = primes[i];
            while (n <= k) {
                if (nums.count(n+n)) {
                    n += n;
                }
            }


        }

    }
    return 0;
}
