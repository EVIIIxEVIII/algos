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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<string,int> fs;
    unordered_map<string,int> fl;
    unordered_map<string,int> sl;
    unordered_map<string,int> all;

    unordered_set<string> seen;

    auto get_key_2 = [&](int n1, int n2) {
        return to_string(n1)+','+to_string(n2);
    };

    auto get_key_3 = [&](int n1, int n2, int n3) {
        return to_string(n1)+','+to_string(n2)+','+to_string(n3);
    };

    for (int i = 0; i < n - 2; ++i) {
        int a1 = a[i];
        int a2 = a[i+1];
        int a3 = a[i+2];

        fs[get_key_2(a1,a2)]++;
        fl[get_key_2(a1,a3)]++;
        sl[get_key_2(a2,a3)]++;
        all[get_key_3(a1,a2,a3)]++;
    }

    long long ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        int a1 = a[i];
        int a2 = a[i+1];
        int a3 = a[i+2];

        int all_cnt = all[get_key_3(a1,a2,a3)];

        if (seen.insert(get_key_3(a1,a2,a3)).second) {
            ans += (fs[get_key_2(a1,a2)] - all_cnt)*all_cnt;
            ans += (fl[get_key_2(a1,a3)] - all_cnt)*all_cnt;
            ans += (sl[get_key_2(a2,a3)] - all_cnt)*all_cnt;
        }
    }

    cout << ans/2 << '\n';
}

//8
//2 1 1 2 1 1 1 1
//
// 2 1 1
// 1 1 2
// 1 2 1
// 2 1 1
// 1 1 1
// 1 1 1
