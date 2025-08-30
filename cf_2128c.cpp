#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) { cin >> a[i]; }

        int prevMin = a[0];
        bool ans = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] - prevMin >= prevMin) {
                ans = false;
                break;
            }

            prevMin = min(prevMin, a[i]);
        }

        ans ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
