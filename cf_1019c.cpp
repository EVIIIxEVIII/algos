#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> prefix(n);
        vector<int> suffix(n);

        for (int i = 0; i < n; ++i) {
            a[i] = (a[i] <= k) ? 1 : -1;
        }

        prefix[0] = a[0];
        suffix[n-1] = a[n-1];

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                prefix[i] = prefix[i-1] + a[i];
            }

            if (n-i < n) {
                suffix[n-i-1] = suffix[n-i] + a[n-i-1];
            }
        }

        bool case1 = false;
        bool case2 = false;
        bool case3 = false;

        int minPrefix = -1;
        for (int i = 0; i < n; ++i) {
            if (prefix[i] >= 0) {
                if (minPrefix == -1) {
                    minPrefix = i;
                    continue;
                }

                if (prefix[i] - prefix[minPrefix] >= 0) {
                    case1 = true;
                    break;
                }

                if(prefix[i] < prefix[minPrefix]) minPrefix = i;
            }
        }

        int startSeqIdx = -1;
        int endSeqIdx = -1;

        for (int i = 0; i < n; ++i) {
            if (prefix[i] >= 0) {
                startSeqIdx = i;
                break;
            }
        }

        for (int i = n-1; i >= 0; --i) {
            if (suffix[i] >= 0) {
                endSeqIdx = i;
                break;
            }
        }

        if (startSeqIdx != -1 && endSeqIdx != -1 && endSeqIdx > startSeqIdx) {
            case2 = true;
        }

        int minSuffix = -1;
        for (int i = n-1; i >= 0; --i) {
            if (suffix[i] >= 0) {
                if (minSuffix == -1) {
                    minSuffix = i;
                    continue;
                }

                if (suffix[i] - suffix[minSuffix] >= 0) {
                    case3 = true;
                    break;
                }

                if (suffix[i] < suffix[minSuffix]) {
                    minSuffix = i;
                }
            }
        }

        //cout << case1 << case2 << case3 << '\n';
        cout << (case1 || case2 || case3 ? "YES" : "NO") << '\n';
    }
    return 0;
}
