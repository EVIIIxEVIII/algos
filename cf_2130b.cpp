#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;
        int s; cin >> s;


        int base_sum = 0;

        vector<int> a(n);
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            base_sum += a[i];
            if (a[i] == 0) zeros++;
            else if (a[i] == 1) ones++;
            else if (a[i] == 2) twos++;
        }

        a.clear();
        if (s == base_sum + 1 || base_sum > s) {
            for (int i = 0; i < zeros; ++i) a.push_back(0);
            for (int i = 0; i < twos; ++i) a.push_back(2);
            for (int i = 0; i < ones; ++i) a.push_back(1);
            for (int i = 0; i < n; ++i) cout << a[i] << ' ';
            cout << '\n';
        } else {
            cout << "-1" << '\n';
        }
    }

    return 0;
}
