#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long>& primes);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;
    vector<bool> is_prime(1e6+1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long i = 2; i <= 1e6; ++i) {
        if (is_prime[i]) {
            for (long long j = 1LL*i*i; j <= 1e6; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    vector<long long> primes;
    for (long long i = 2; i < 1e6; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    while (t--) solve(primes);

    return 0;
}

void solve(vector<long long>& primes) {
    long long n; cin >> n;

    for (long long i = 0; i < n; ++i) {
        cout << primes[i] * primes[i+1] << ' ';
    }

    cout << '\n';
}
