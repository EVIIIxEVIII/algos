#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        string s;
        s.resize(n);
        for (int i = 0; i < n; ++i) cin >> s[i];

        vector<vector<int>> a;
        int num; cin >> num;
        int lastNum = num;
        a.push_back({0});
        a.push_back({lastNum});

        for (int i = 0; i < m-1; ++i) {
            int num; cin >> num;
            if (num == lastNum + 1) {
                a.back().push_back(num);
            } else {
                a.push_back({num});
            }
        }

        for (int i = 0; i < n; ++i) {
            if () {

            }


        }



    }
    return 0;
}
