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
    int n; cin >> n;

    vector<long long> f(n);

    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }


    vector<long long> ans(n, 0);
    for (int i = 1; i < n-1; ++i) {
        ans[i] = ((f[i+1] - f[i]) - (f[i] - f[i - 1])) / 2;
    }

    long long total = accumulate(ans.begin()+1, ans.end()-1, 0);

    //ans[0] = total - init;

    long long first_sum = 0;
    for (int i = 0; i < n; ++i) {
        first_sum += ans[i] * i;
    }

    ans[n-1] = (f[0] - first_sum) / (n-1);

    long long second_sum = 0;
    for (int i = 0; i < n; ++i) {
        second_sum += ans[i] * (i-1);
    }

    ans[0] = f[1] - second_sum;

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
