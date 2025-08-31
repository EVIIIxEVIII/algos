#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tt; cin >> tt;

    while (tt--) {

        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        string ans = "";

        int l = 0, r = n - 1;
        bool greater = true;
        for (int i = 0; i < n; ++i) {
            char val;

            if (greater) {
                if (a[l] > a[r]) { val = 'L'; l++; }
                else { val = 'R'; r--; }
            } else {
                if (a[l] > a[r]) { val = 'R'; r--; }
                else { val = 'L'; l++; }
            }

            ans.push_back(val);
            greater = !greater;
        }

        cout << ans << '\n';
    }

    return 0;
}
