#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // idea:
        // start with asking about 1
        // if yes, append 1 to the front, otherwise the answer is trivially 00...000
        // if the answer for 11 is false, try 01 and so on until you find a potition such that
        // both 1 and 0 result into false, then you do the same for the right side.

        string ans = "1";
        cout << "? " << ans << '\n'; cout.flush();
        int reply; cin >> reply;
        if (!reply) {
            cout << "! " << string(n, '0') << '\n'; cout.flush();
            continue;
        }

        for (int i = 0; i < n-1; ++i) {
            cout << "? " << "0" + ans << '\n'; cout.flush();
            int reply; cin >> reply;
            if (reply) {
                ans = '0' + ans;
                continue;
            }

            cout << "? " << "1" + ans << '\n'; cout.flush();
            cin >> reply;
            if (reply) {
                ans = '1' + ans;
            } else {
                break;
            }
        }

        if (ans.size() == n) {
            cout << "! " << ans << '\n'; cout.flush();
            continue;
        }

        int left = n - ans.size();
        for (int i = 0; i < left; ++i) {
            cout << "? " << ans + "0" << '\n'; cout.flush();
            int reply; cin >> reply;
            if (reply) {
                ans = ans + '0';
            } else {
                ans = ans + '1';
            }
        }

        cout << "! " << ans << '\n'; cout.flush();
    }
    return 0;
}
