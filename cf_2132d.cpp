#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long k;
        cin >> k;

        long long ans = 0;
        long long pow10 = 1;
        string s;
        char digit_index;

        for (int l = 1; ; ++l) {
            long long block = 9 * pow10 * l;
            if (k > block) {
                k -= block;
                pow10 *= 10;
            } else {
                long long number = pow10 + (k - 1) / l;

                digit_index = (k - 1) % l;
                s = to_string(number);
                break;
            }
        }

        for (int i = 0; i < digit_index; ++i) {
            ans += s[i] - '0';
        }

        cout << s << '\n';

    }
    return 0;
}

