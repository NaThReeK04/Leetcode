class Solution {
public:
    int check(int num, vector<int>& differences, int lower, int upper) {
        for (int diff : differences) {
            num += diff; 
            if (num < lower || num > upper) return num;
        }
        return num;
    }

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mini = -1, maxi = -1;

        int left = lower, right = upper,lowest=lower-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int ans=check(mid,differences,lower,upper);
            if (ans>=lower && ans<=upper) {
                lowest=mid;
                right = mid - 1;
            } else if(ans<lower) {
                left = mid + 1;
            }else{
                right=mid-1;
            }
        }

        left = lower, right = upper;int largest=upper+1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int ans=check(mid, differences, lower, upper);
            if (ans>=lower && ans<=upper) {
                largest=mid;
                left = mid + 1;
            } else if(ans<lower){
                left = mid + 1;
            }else{
                right=mid-1;
            }
        }
        if(lowest==lower-1)return 0;
        return largest-lowest+1;
    }
};
