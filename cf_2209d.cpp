#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int r, g, b;
    cin >> r >> g >> b;

    pair<int, char> x = {r, 'R'};
    pair<int, char> y = {g, 'G'};
    pair<int, char> z = {b, 'B'};

    if (y.first < z.first) swap(y, z);
    if (x.first < y.first) swap(x, y);
    if (y.first < z.first) swap(y, z);

    if (y.first == 0) {
        cout << x.second << '\n';
        return;
    }

    if (z.first == 0) {
        string ans;
        int doubles = y.first;
        for (int i = 0; i < doubles; ++i) {
            ans.push_back(x.second);
            ans.push_back(y.second);
            x.first--; y.first--;
        }

        if (x.first) ans.push_back(x.second);
        cout << ans << '\n';
        return;
    }

    string ans;
    if (x.first < z.first + y.first) {
        ans.push_back(z.second);
        ans.push_back(x.second);
        ans.push_back(y.second);
        z.first--; x.first--; y.first--;
    }

    while (x.first < z.first + y.first) {
        ans.push_back(ans[ans.size()-2]);
        ans.push_back(ans[ans.size()-2]);
        ans.push_back(ans[ans.size()-5]);
        z.first--; x.first--; y.first--;
    }

    reverse(ans.begin(), ans.end());
    while (y.first > 0 || z.first > 0) {
        ans.push_back(x.second);
        x.first--;

        if (y.first > 0) {
            ans.push_back(y.second);
            y.first--;
        } else {
            ans.push_back(z.second);
            z.first--;
        }
    }

    if (x.first) ans.push_back(x.second);
    cout << ans << '\n';
}
