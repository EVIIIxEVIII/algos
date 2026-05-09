#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        unordered_set<string> all_pts;

        for (auto& p : points) {
            string str_ptr;
            str_ptr += (char)(p[0]+'0');
            str_ptr += (char)(p[1]+'0');
            str_ptr += (char)(p[2]+'0');
            all_pts.insert(str_ptr);
        };

        string t;
        t += (char)(target[0]+'0');
        t += (char)(target[1]+'0');
        t += (char)(target[2]+'0');

        int k = 0;
        while (true) {
            if (all_pts.contains(t)) {
                break;
            }

           unordered_set<string> cand;
            for (auto& p1 : all_pts) {
                for (auto& p2 : all_pts) {
                    if (p1 != p2) {
                        int x1 = p1[0] - '0';
                        int y1 = p1[1] - '0';
                        int z1 = p1[2] - '0';

                        int x2 = p2[0] - '0';
                        int y2 = p2[1] - '0';
                        int z2 = p2[2] - '0';

                        int x3 = (x1 + x2) / 2;
                        int y3 = (y1 + y2) / 2;
                        int z3 = (z1 + z2) / 2;

                        string p3_str;
                        p3_str += (char)(x3 +'0');
                        p3_str += (char)(y3+'0');
                        p3_str += (char)(z3+'0');

                        if (!all_pts.contains(p3_str)) {
                            cand.insert(p3_str);
                        }
                    }
                }
            }

            if (!cand.empty()) {
                for (auto& c : cand) {
                    all_pts.insert(c);
                }
            } else {
                k = -1;
                break;
            }
            k++;
        }

        return k;
    }
};
