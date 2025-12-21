#include <bits/stdc++.h>
using namespace std;

const long long prime = 1'000'000'000 + 7;

long long pow_(long long a, long long b) {
    if (b == 0) return 1;

    long long t = pow_(a, b/2);
    if (b % 2 == 0) {
        return (t * t) % prime;
    } else {
        return (((t * t) % prime) * a) % prime;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    long long exp = 0;
    for (int i = 0; i < n; ++i) {
        exp += a[i];
    }

    return 0;
}
