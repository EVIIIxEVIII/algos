#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> isPrime(32000, true);
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i * i * 1LL < 32000; ++i) {
        if (isPrime[i]) {
            for (long long j = i * i * 1LL; j < 32000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int k = 1;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                k *= i;

                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        if (n > 1) {
            k *= n;
        }

        cout << k << '\n';
    }
    return 0;
}
