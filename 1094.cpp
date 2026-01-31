#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        long long global_cap = 0;

        for (int i = 0; i < trips.size(); ++i) {
            long long local_cap = trips[i][0];

            for (int j = 0; j < trips.size(); ++j) {
                if (i == j) continue;

                if (max(trips[i][1], trips[j][1]) < min(trips[j][2], trips[i][2])) {
                    local_cap += trips[j][0];
                }
            }

            global_cap = max(global_cap, local_cap);
        }

        return global_cap <= capacity;
    }
};
