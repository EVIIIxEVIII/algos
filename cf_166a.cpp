#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    n++;
    bool found = false;
    while (!found) {
        int a1 = (n / 1000);
        int a2 = (n / 100) % 10;
        int a3 = (n / 10) % 10;
        int a4 = (n) % 10;


        if (a1 != a2 && a1 != a3 && a1 != a4 && a2 != a3 && a2 != a4 && a3 != a4) {
            found = true;
            cout << n << '\n';
        }

        n++;
    }


    return 0;
}
