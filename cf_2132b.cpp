#include <bits/stdc++.h>

using namespace std;

int digits(uint64_t x) {
    if (x == 0) return 1;
    int c = 0;
    while (x != 0) {
        x /= 10;
        ++c;
    }
    return c;
}

uint64_t pow10u(int k) {
    uint64_t p = 1;
    while (k--) p *= 10;
    return p;
}

int main() {
    int tt; cin >> tt;

    while(tt--) {
        uint64_t n; cin >> n;

        vector<uint64_t> ans;
        for (int i = digits(n); i >= 1; --i) {
            if (n % (pow10u(i) + 1) == 0) {
                ans.push_back(n / (uint64_t)(pow(10, i) + 1));
            }
        }

        cout << ans.size() << '\n';
        if (!ans.size()) continue;

        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
