#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int ctr = 0;
        int score = 0;

        for (const std::string& e : events) {
            if (ctr == 10) break;

            if (std::isdigit(e[0])) {
                score += e[0]-'0';
            } else if (e == "W") {
                ctr++;
            } else {
                score++;
            }
        }

        vector<int> ans = {score, ctr};
        return ans;
    }
};
