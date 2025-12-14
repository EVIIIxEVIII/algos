#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<bool> primes(1000'001, true);
    primes[0] = false;
    primes[1] = false;

    long long maxPrime = 1000'001;
    for (long long i = 2; i < maxPrime; i++) {
        for (long long j = i * i; j <= maxPrime; j += i) {
            primes[j] = false;
        }
    }

    set<long long> tPrimes;
    for (long long i = 0; i < maxPrime; ++i) {
        if (primes[i]) tPrimes.insert(i*i);
    }

    for (int i = 0; i < n; ++i) {
        if (tPrimes.count(a[i])) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
