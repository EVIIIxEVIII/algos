#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b) {
    if (b == 0) return 1;

    long long tmp = power(a, b/2);
    if (b % 2 == 0) {
        return tmp * tmp;
    } else {
        return tmp * tmp * a;
    }
}

long long power2(long long a, long long b) {
    long long res = 1;

    while (b > 0) {
        if (b % 2) res *= a;
        a *= a;
        b /= 2;
    }

    return res;
}

long long power3(long long a, long long b) {
    long long res = 1;
    long long temp = a;

    while (b > 0) {
        if (b & 1) {
            res *= temp;
        }
        temp *= temp;
        b >>= 1;
    }
    return res;
}

long long power_mod(long long a, long long b) {
    static constexpr long long prime = 998244353;

    long long res = 1 % prime;
    long long temp = a % prime;

    while (b > 0) {
        if (b & 1) {
            res = (res * temp) % prime;
        }

        temp = (temp * temp) % prime;
        b >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}
