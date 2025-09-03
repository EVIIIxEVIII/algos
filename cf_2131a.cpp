#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; ++i) { cin >> a[i];  }
        for (int i = 0; i < n; ++i) { cin >> b[i];  }
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            ans += max(a[i] - b[i], 0);
        }

        cout << ans << '\n';
    }

    return 0;
}
