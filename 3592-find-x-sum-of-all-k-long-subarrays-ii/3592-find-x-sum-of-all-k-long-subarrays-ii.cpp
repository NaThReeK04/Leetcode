class Solution {
public:

    set<pair<int,int>>lowFreqValue;

    vector<int> findMaxFromLowSet() {
        auto it = lowFreqValue.end(); it--;
        pair<int,int>freqValue = *it;
        int f = freqValue.first;
        int val = freqValue.second;

        return {f,val};
    }

    void insert(int currF, int currVal, set<pair<int,int>>&topFreqValue, set<pair<int,int>>&lowFreqValue, long long &currSum, int x) {
            
        if(lowFreqValue.empty()) {
            topFreqValue.insert({currF,currVal});
            currSum += (1LL*currF*currVal);
        }
        else{
            vector<int> v = findMaxFromLowSet();
            int f = v[0];
            int val = v[1];

            if(f > currF || (f  == currF && val > currVal)) {
                topFreqValue.insert({f,val});
                currSum += (1LL*f*val);
                lowFreqValue.erase({f,val});
                lowFreqValue.insert({currF,currVal});
            }else {
                topFreqValue.insert({currF,currVal});
                currSum += (1LL*currF*currVal);
            }
        }

        if(topFreqValue.size() > x) {
            pair<int,int>lowestOfTop = *topFreqValue.begin();
            topFreqValue.erase(topFreqValue.begin());
            currSum -= (1LL*lowestOfTop.first * lowestOfTop.second);

            lowFreqValue.insert(lowestOfTop);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int,int>freq;
        set<pair<int,int>>topFreqValue;

        for(int i=0; i<k; i++) {
            freq[nums[i]]++;
        }

        long long currSum = 0;
        
        for(auto p : freq) {
            int currVal = p.first, currF = p.second;
            insert(currF,currVal,topFreqValue,lowFreqValue,currSum,x);
        }

        vector<long long>ans;
        ans.push_back(currSum);

        for(int i=k; i<n; i++) {
            if(nums[i] == nums[i-k]) {
                ans.push_back(currSum);
                continue;
            }

            int prev = nums[i-k];
            int f = freq[prev];

            if(topFreqValue.find({f,prev}) != topFreqValue.end()) {
                topFreqValue.erase({f,prev});
                currSum -= (1LL*f*prev);
            } 
            else lowFreqValue.erase({f,prev});

            int currx = nums[i];
            int currf = freq[currx];

            if(topFreqValue.find({currf,currx}) != topFreqValue.end()) {
                topFreqValue.erase({currf,currx});
                currSum -= (1LL*currf*currx);
            }
            else lowFreqValue.erase({currf,currx});
            
            freq[prev]--;
            insert(freq[prev],prev,topFreqValue,lowFreqValue,currSum,x);

            freq[currx]++;
            insert(freq[currx],currx,topFreqValue,lowFreqValue,currSum,x);

            ans.push_back(currSum);
        }
        return ans;
    }
};