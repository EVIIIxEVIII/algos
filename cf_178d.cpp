#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        // idea: if the sum of the numbers is equal to a prefix sum of the primes array, then it is possible to
        // do the operation to make the array equal to an array of primes which will have gcd(a_i, a_j) = 1 for all i, j s.t i != j

        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> isPrime(1e6, true);
        isPrime[0] = isPrime[1] = false;

        for (long long i = 2; i * i * 1LL < 1e6; ++i) {
            if (isPrime[i]) {
                for (long long j = i * i * 1LL; j < 1e6; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (long long i = 2; i < 1e6; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        vector<long long> pref;
        pref.push_back(primes[0]);

        for (int i = 1; i < primes.size(); ++i) {
            pref.push_back(pref[i-1] + primes[i]);
        }

        // is it even needed?
        //sort(a.begin(), a.end(), greater<int>());

        long long sum = 0;
        int ans = 0;

        for (int k = 1; k <= n; ++k) {
            sum += a[k - 1];
            if (sum >= pref[k - 1]) {
                ans = k;
            }
        }

        cout << n - ans << '\n';
    }

    return 0;
}
