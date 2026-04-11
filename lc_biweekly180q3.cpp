#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<bool> is_prime(1e5+4, true); // next primes is 1e5 + 3
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= 1e5+4; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= 1e5+4; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 0; i <= 1e5+4; ++i) {
            if (is_prime[i]) primes.push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                if (!is_prime[nums[i]]) {
                    // should not throw because there is 1e5+3
                    auto it = upper_bound(primes.begin(), primes.end(), nums[i]);
                    ans += *it - nums[i];
                }
            } else {
                if (is_prime[nums[i]]) {
                    ans += 1 + (nums[i] == 2); // makes it even besides 2
                }
            }
        }

        return ans;
    }


};
