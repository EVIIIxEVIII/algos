#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) cin >> a[i];

        queue<vector<int>> memo;
        memo.push(a);

        int bestFallDamage = 0;
        int totalDamage = 0;
        for (int i = 0; i < n; ++i) totalDamage += a[i];

        while (!memo.empty()) {
            auto slice = memo.front();
            memo.pop();

            int bestCut = -1;
            int bestCutIdx = -1;

            for (int i = 0; i < slice.size()-1; ++i) {
                int diff = slice[i+1] - (i+1);

                int score = i+1;
                if (slice[i+1] - (i+1) > 0) {
                    if (bestCut > score) {
                        bestCut = score;
                        bestCutIdx = i;
                    }
                } else {
                    if (i+2 < slice.size()) {
                        for (int j = i+2; j < slice.size(); ++j) {
                            if (slice[j] == 1) {
                                score++;
                            }
                        }
                    }

                    if (bestCut > score) {
                        bestCut = score;
                        bestCutIdx = i;
                    }
                }

                int cut = bestCutIdx+1;
                for (int i = bestCutIdx+1; i < slice.size(); ++i) {
                    if (slice[i] - cut > 0) {
                        slice[i] -= cut;
                        break;
                    } else {
                        cut = 1;
                    }
                }

                bestFallDamage += bestCut;

                if (bestCutIdx > 1) {
                    memo.push(vector<int>(slice.begin(), slice.begin() + bestCutIdx));
                }
                if (bestCutIdx < (int)slice.size() - 1) {
                    memo.push(vector<int>(slice.begin() + bestCutIdx + 1, slice.end()));
                }
            }
        }

        cout << totalDamage - bestFallDamage << '\n';
    }

    return 0;
}
