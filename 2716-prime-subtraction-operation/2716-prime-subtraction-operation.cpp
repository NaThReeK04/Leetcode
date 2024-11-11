class Solution {
public:
    vector<int> SieveOfEratosthenes(int n) {
        vector<bool> isPrime(n + 1, true);
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p)
                    isPrime[i] = false;
            }
        }
        
        vector<int> primes;
        for (int p = 2; p <= n; p++) {
            if (isPrime[p])
                primes.push_back(p);
        }
        return primes;
    }

    bool primeSubOperation(vector<int> &nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> primes = SieveOfEratosthenes(maxNum);

        for (int i = 0; i < nums.size(); i++) {
            bool adjusted = false;
            for (int j = primes.size() - 1; j >= 0; j--) {
                if (primes[j] < nums[i] && (i == 0 || nums[i] - primes[j] > nums[i - 1])) {
                    nums[i] -= primes[j];
                    adjusted = true;
                    break;
                }
            }
            
            if (i > 0 && nums[i] <= nums[i - 1])
                return false;
        }

        return true;
    }
};

