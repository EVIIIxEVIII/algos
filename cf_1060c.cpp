
#include <bits/stdc++.h>
using namespace std;


bool prime_factors(set<int>& primeFactors, int num, bool add) {
    if (num % 2 == 0) {
        if (primeFactors.find(2) != primeFactors.end()) {
            return true;
        }

        if (add) primeFactors.insert(2);
        while (num % 2 == 0) {
            num /= 2;
        }
    }

    for (int j = 3; j * j <= num; j += 2) {
        if (num % j == 0) {
            if (primeFactors.find(j) != primeFactors.end()) {
                return true;
            }

            if (add) primeFactors.insert(j);
            while (num % j == 0) {
                num /= j;
            }
        }
    }

    if (num > 1) {
        if (primeFactors.find(num) != primeFactors.end()) {
            return true;
        }
        if (add) primeFactors.insert(num);
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
        }

        set<int> primeFactors;
        bool isZero = false;

        for (int i = 0; i < n; ++i) {
            bool res = prime_factors(primeFactors, a[i], true);
            if (res) {
                isZero = true;
                break;
            }
        }

        if (isZero) {
            cout << 0 << '\n';
            continue;
        }

        bool isOne = false;
        for (int i = 0; i < n; ++i) {
            bool res = prime_factors(primeFactors, a[i]+1, false);
            if (res) {
                isOne = true;
                break;
            }
        }

        if (isOne) {
            cout << 1 << '\n';
            continue;
        }

        cout << 2 << '\n';
    }
    return 0;
}
