#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> map;
        sort(hand.begin(), hand.end());

        int current = -1;
        int groupIdx = 0;
        for (int i = 0; i < hand.size(); ++i) {
            if (current != hand[i]) {
                current = hand[i];
                map[hand[i]] = i;
            }
        }

        for (int i = 0; i < hand.size(); ++i) {
            if (map.find(hand[i]) == map.end()) {
                continue;
            }

            for (int j = 0; j < groupSize; ++j) {
                if (map.find(hand[i]+j) == map.end()) {
                    return false;
                } else {
                    int startIdx = map[hand[i]+j];
                    if (startIdx + 1 < hand.size() && hand[startIdx + 1] == hand[startIdx]) {
                        map[hand[i]+j]++;
                    } else {
                        map.erase(hand[i]+j);
                    }
                }
            }
        }

        return true;
    }
};
