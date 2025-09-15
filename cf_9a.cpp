#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a; cin >> a;
    int b; cin >> b;

    int target = max(a, b);
    int num = 6 - target + 1;
    int den = 6;

    while ((num % 2 == 0 && den % 2 == 0)) {
        num /= 2;
        den /= 2;
    }

    if (num % 3 == 0 && den % 3 == 0) {
        num /= 3;
        den /= 3;
    }

    cout << num << '/' << den << endl;

    return 0;
}
