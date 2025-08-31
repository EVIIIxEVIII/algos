#include <vector>
#include <iostream>


using namespace std;

int main() {
    int tt; cin >> tt;

    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        int sumAns = 0;

        for (int i = 0; i < n; ++i) {
            sumAns += a[i];
        }

        int zeros = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                zeros++;
            }
        }

        cout << sumAns + zeros << '\n';
    }

    return 0;
}
