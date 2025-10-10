#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;

        unordered_map<long long, long long> a;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a[x]++;
        }

        int sides = 0;
        long long ans = 0;

        vector<int> left;
        for (auto &[num, freq] : a) {
            if (freq % 2 == 0) {
                ans += freq * num;
                sides += freq;
            } else {
                ans += (freq-1) * num;
                sides += (freq-1);
            }

            a[num] = freq%2;
            if(a[num]) left.push_back(num);
        }

        sort(left.begin(), left.end(), greater<int>());

        int candidate = 0;
        int csides = 0;
        for (int i = 0; i < left.size(); ++i) {
            if (i+1 < left.size() && left[i] < ans + left[i+1] && left[i] + left[i+1] > candidate) {
                candidate = left[i] + left[i+1];
                csides = 2;
            }

            if (left[i] < ans && left[i] > candidate) {
                candidate = left[i];
                csides = 1;
            }
        }

        ans += candidate;
        sides += csides;

        cout << (sides >= 3 ? ans : 0) << '\n';
    }
    return 0;
}
