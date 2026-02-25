#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long x;
        cin >> x;

        // 64 -> 10 F(64) = 10, F(10) = 1
        // 3 -> 2, 1 -> 3

        vector<long long> digits;
        while (x >= 10) {
            long long digit = x % 10;
            digits.push_back(digit);
            x /= 10;
        }

        long long first_digit = x;
        sort(digits.begin(), digits.end());

        int moves = digits.size();
        int sum = first_digit;

        for (size_t i = 0; i < digits.size(); ++i) {
            if (sum + digits[i] < 10) {
                moves--;
                sum += digits[i];
            } else {
                break;
            }
        }

        int sum_with_first = 1;
        int moves_with_first = digits.size() + 1;
        for (size_t i = 0; i < digits.size(); ++i) {
            if (sum_with_first + digits[i] < 10) {
                moves_with_first--;
                sum_with_first += digits[i];
            } else {
                break;
            }
        }

        cout << min(moves, moves_with_first) << '\n';
    }
    return 0;
}
