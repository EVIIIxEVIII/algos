#include <string>
#include <queue>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int m = s1.size();
        int n = s2.size();

        std::queue<int> candidatesS1;
        std::queue<int> candidatesS2;

        if (s1[0] == s3[0]) {
            candidatesS1.push(0);
        }

        if (s2[0] == s3[0]) {
            candidatesS2.push(0);
        }

        for (int i = 1; i < s3.size() - 1; ++i) {
            int c1 = candidatesS1.size();
            int c2 = candidatesS2.size();

            for (int j = 0; j < c1; ++j) {
                int idx = candidatesS1.front();
                candidatesS1.pop();

                if (idx + 1 < s2.size() && s2[idx + 1] == s3[i]) {
                    candidatesS2.push(idx);
                }

                if (idx + 1 < s1.size() && s1[idx + 1] == s3[i]) {
                    candidatesS1.push(idx);
                }
            }

            for (int j = 0; j < c2; ++j) {
                int idx = candidatesS2.front();
                candidatesS2.pop();

                if (idx + 1 < s2.size() && s2[idx + 1] == s3[i]) {
                    candidatesS2.push(idx);
                }

                if (idx + 1 < s1.size() && s1[idx + 1] == s3[i]) {
                    candidatesS1.push(idx);
                }
            }

        }

        return (candidatesS1.size() != 0) && (candidatesS2.size() != 0);
    }
};
