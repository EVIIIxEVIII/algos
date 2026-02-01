#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        // idea: the condition that max(p[i], p[i+1]) > p[i+2] implies that the whole array p
        // is made out of these decreasing subarrays interrupted by places where p[i] < p[i+1]
        //
        // idea: if we split the array into these decreasing subarrays with each subarray being of
        // some length x, we would know that all the subarrays in that subarray would have the LDS equal to the
        // size of the subarray, i.e we would be able to do x * 1 + (x - 1) * 2 + ...
        //
        // question: but what about the positions where the "split" between two descreasing subarrays happens?

        long long n;
        cin >> n;

        vector<long long> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        long long sum = n * (n + 1) / 2;
        for (long long i = 0; i < n - 1; ++i) {
            if (p[i] > p[i+1]) {
                sum += (i+1) * (n - (i+1)); // l in [0, i] and r in [i+1, n]
            }
        }

        cout << sum << '\n';
    }
    return 0;
}
