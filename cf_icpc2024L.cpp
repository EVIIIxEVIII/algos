#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 25 + 25 = 50 <= 60, so plancks of 25 should be combined and we have n / 2 of them
    // 18 + 21 + 21 = 60 <= 60, so this is the correct combo
    // if we do this we have n 25s, n 21s, and n / 2 18 and we used n plancks
    //
    // we now need to know how many plancks do we need to craft the remaining n / 2 18 planck
    // each 60 planck can be split to 3 18 plancks
    // so we need (n / 2) / 3 = n / 6
    // but we need to ceil, because we might have n being odd, which would mean we had only n/2 - 1 18 plancks
    // crafted, and we might have n not divisible by 3, so we need to add for the leftover planks
    //
    // the main takeaway: when doing ceil for n != 2, you have to add n - 1, not just 1

    cout << n + ((n + 5) / 6) << '\n';

    return 0;
}
