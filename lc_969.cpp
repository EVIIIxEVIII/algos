#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = int(arr.size());

        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            int max_i = 0;
            int max_val = arr[0];

            for (int j = 0; j < n - i; ++j) {
                if (max_val < arr[j]) {
                    max_val = arr[j];
                    max_i = j;
                }
            }

            if (max_i + 1 != n - i) {
                ans.push_back(max_i+1);
                ans.push_back(n-i);

                reverse(arr.begin(), arr.begin()+max_i+1);
                reverse(arr.begin(), arr.end()-i);
            }
        }

        return ans;
    }
};
