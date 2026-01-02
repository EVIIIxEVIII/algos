#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        vector<int> a_map(n+1);
        vector<int> b_map(n+1);

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
            a_map[x] = i;
        }

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b[i] = x;
            b_map[x] = i;
        }

        int valid = true;
        int check = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                if (n % 2 == 0 || check) {
                    valid = false;
                    break;
                }
                check = true;
            } else if (a[i] != b[a_map[b[i]]]) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << -1 << '\n';
            continue;
        }

        vector<array<int, 2>> ans;
        int mid = n / 2;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i] && i != mid) {
                int v1 = b[i];
                int v2 = b[mid];

                swap(b[i], b[mid]);
                swap(a[i], a[mid]);
                b_map[v1] = mid;
                b_map[v2] = i;

                ans.push_back({i + 1, mid + 1});
                break;
            }
        }

        for (int i = 0; i < n / 2; ++i) {
            int j = n - 1 - i;
            int p = b_map[a[i]];
            if (p == j) continue;

            ans.push_back({p + 1, j + 1});

            b_map[b[p]] = j;
            b_map[b[j]] = p;

            swap(a[p], a[j]);
            swap(b[p], b[j]);
        }

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i][0] << ' ' << ans[i][1] << '\n';
        }
    }
    return 0;
}
