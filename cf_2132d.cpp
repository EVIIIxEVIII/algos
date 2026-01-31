#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long k{};
        cin >> k;

        int digit_index{};
        long long number{};

        int c = 1;
        long long pow10 = 1;

        for (;;++c) {
            long long block = 9 * pow10 * c;
            if (k > block) {
                k -= block;
                pow10 *= 10;
            } else {
                number = pow10 + (k - 1) / c;
                digit_index = (k - 1) % c;
                break;
            }
        }

        string original_s = to_string(number++);

        long long ans = 0;
        for (int i = 0; i <= digit_index; ++i) {
            ans += original_s[i] - '0';
        }

        long long boundary = number - 1;
        string s = to_string(boundary);
        int l = s.size();

        vector<long long> p10(l+1, 1);
        p10[0] = 1;

        for (int i = 1; i <= l; ++i) {
            p10[i] = p10[i-1] * 10;
        }

        // (0 + 1 + 2 + 3 + ... + d1 - 1) * 10^(l-1) -> summing the most significant digits d
        // such that d < the most significant digit of n - 1. Each number from 1 to d1 - 1 appears exactly 10^(l-1) times

        //So after the MSD there are l - 1 digits, each one of those digits can have a value from 0 to 9,
        //and for each value from 0 to 9 there are 10^(l - 2) situations when that number is present in the number,
        //because if we fix some digit then all the other l - 2 digits can be changed, right? so we count like this:
        //say we fix digit dn to some value from 0 to 9, but because all the other l - 2 digits can move we have to
        //count each one of the digits from 0 to 9 10^(l - 2) times, right? so we have sum(0, 9) * 10^(l - 2) * (l - 1) * d1,
        //because there are l - 1 such positions, for each such position there are numbers from 0 to 9 and each one of them
        //can appear 10^(l - 2) times and there are 0 to d1-1 such blocks, so d1 blocks including 0.

        int pref = 0;

        for (int i = 0; i < s.size(); ++i) {
            int di = s[i] - '0';
            int rem = l - i - 1;

            if (di) {
                ans += 1LL * (di * (di - 1) / 2 + pref * di) * p10[rem];
                if (rem > 0) {
                    ans += 45LL * rem * p10[rem - 1] * di;
                }
            }

            pref += di;
        }

        cout << ans << '\n';
    }

    return 0;
}

