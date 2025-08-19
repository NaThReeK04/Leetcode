#include <vector>
#include <cmath>

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Helper function for modular exponentiation (to find modular inverse)
    // Computes (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper function to find modular inverse using Fermat's Little Theorem
    // Assumes MOD is a prime number
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    int xorAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        // Block size for square root decomposition
        int blockSize = static_cast<int>(sqrt(n));

        // diffs[k][i] stores multiplicative changes for progressions with small step k
        std::vector<std::vector<long long>> diffs(blockSize + 1, std::vector<long long>(n + 1, 1));

        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k > blockSize) {
                // Case 1: Large k. Brute-force is fast enough.
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            } else {
                // Case 2: Small k. Defer updates using difference array.
                long long v_inv = modInverse(v);
                diffs[k][l] = (diffs[k][l] * v) % MOD;
                
                // The number of elements affected is (r - l) / k + 1
                // The next index in the progression after r is l + num_elements * k
                long long num_elements = (r - l) / k + 1;
                long long stop_idx = l + num_elements * k;

                if (stop_idx <= n) {
                    diffs[k][stop_idx] = (diffs[k][stop_idx] * v_inv) % MOD;
                }
            }
        }

        // Apply the deferred updates for small k
        for (int k = 1; k <= blockSize; ++k) {
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    // Propagate the factor from the previous element in the progression
                    diffs[k][i] = (diffs[k][i] * diffs[k][i - k]) % MOD;
                }
                // Apply the final cumulative factor to the number
                nums[i] = (1LL * nums[i] * diffs[k][i]) % MOD;
            }
        }

        // Calculate the final XOR sum
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};