#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long defaultScore = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2) {
                defaultScore -= a[i];
            } else {
                defaultScore += a[i];
            }
        }

        long long oddMin = LLONG_MAX / 2;
        long long evenMin = LLONG_MAX / 2;
        long long maximumGain = 0;

        for (int i = 0; i < n; ++i) {
            if (i % 2) {
                maximumGain = max(i + a[i] + a[i] - evenMin, maximumGain);
                oddMin = min(oddMin, i - a[i] - a[i]);
            } else {
                evenMin = min(evenMin, i + a[i] + a[i]);
                maximumGain = max(i - a[i] - a[i] - oddMin, maximumGain);
            };
        }

        if (n > 2) {
            if (n % 2 == 0) {
                maximumGain = max(maximumGain, (long long)(n - 2));
            } else {
                maximumGain = max(maximumGain, (long long)(n - 1));
            }
        }

        cout << maximumGain + defaultScore << '\n';
    }

    return 0;
}

