#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // a_{i+1} - a_{i} ==  1 => same and prev was L
        // a_{i+1} - a_{i} == -1 => same and prev was R
        //
        // |a_{i+1} - a_{i}| == 0 => different

        int count = 0;

        string cand1;
        string cand2;
        cand1.resize(n);
        cand2.resize(n);

        for (int i = 0; i < n; ++i) cand1[i] = '?';
        for (int i = 0; i < n; ++i) cand2[i] = '?';

        cand1[0] = 'L';
        cand2[0] = 'R';

        for (int i = 0; i < n-1; ++i) {
            if (a[i+1] - a[i] == 1) {
                cand1[i+1] = 'L';
                cand2[i+1] = 'L';
            } else if (a[i+1] - a[i] == -1) {
                cand1[i+1] = 'R';
                cand2[i+1] = 'R';
            } else if (a[i+1] - a[i] == 0) {
                cand1[i+1] = cand1[i] == 'L' ? 'R' : 'L';
                cand2[i+1] = cand2[i] == 'R' ? 'L' : 'R';
            } else {
                count = -1;
                break;
            }
        }

        if (count == -1) {
            cout << 0 << '\n';
            continue;
        }

        count = 2;
        vector<int> prefixL(n);
        vector<int> sufixR(n);

        prefixL[0] = cand1[0] == 'L';
        sufixR[n-1] = cand1[n-1] == 'R';

        for (int i = 1; i < n; ++i) {
            prefixL[i] = prefixL[i-1] + (cand1[i] == 'L');
        }

        for (int i = n-2; i >= 0; --i) {
            sufixR[i] = sufixR[i+1] + (cand1[i] == 'R');
        }

        for (int i = 0; i < n; ++i) {
            if (sufixR[i] + prefixL[i] != a[i]) {
                count--;
                break;
            }
        }

        fill(prefixL.begin(), prefixL.end(), 0);
        fill(sufixR.begin(), sufixR.end(), 0);

        prefixL[0] = cand2[0] == 'L';
        sufixR[n-1] = cand2[n-1] == 'R';

        for (int i = 1; i < n; ++i) {
            prefixL[i] = prefixL[i-1] + (cand2[i] == 'L');
        }

        for (int i = n-2; i >= 0; --i) {
            sufixR[i] = sufixR[i+1] + (cand2[i] == 'R');
        }

        for (int i = 0; i < n; ++i) {
            if (sufixR[i] + prefixL[i] != a[i]) {
                count--;
                break;
            }
        }

        cout << count << '\n';
        //cout << "I don't know yet" << '\n';
    }
    return 0;
}
