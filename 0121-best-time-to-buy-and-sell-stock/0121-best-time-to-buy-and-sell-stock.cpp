class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=INT_MIN;
        for(int i=1;i<prices.size();i++){
            int profit=prices[i]-mini;
            mini=min(mini,prices[i]);
            maxi=max(maxi,profit);
        }
        return (maxi<0)?0:maxi;
    }
};