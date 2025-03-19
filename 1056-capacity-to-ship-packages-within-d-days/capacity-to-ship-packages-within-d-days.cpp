class Solution {
public:
    long long check(int mid, vector<int>& weights, int days) {
        long long count = 1;
        long long sum = 0;
        
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                sum = weights[i];
                count++;
            }
        }
        
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for (auto it : weights) {
            right += it;
        }

        int ans = 0;
       
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long sum = check(mid, weights, days);
            
            if (sum <= days) {
                ans = mid;  
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        
        return ans;
    }
};
