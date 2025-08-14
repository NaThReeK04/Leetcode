class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=INT_MIN;
        vector<int>leftmax(n);
        vector<int>rightmax(n);
        leftmax[0]=prices[0];
        for(int i=1;i<n;i++){
            leftmax[i]=min(leftmax[i-1],prices[i]);
        }
        rightmax[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],prices[i]);
        }
        for(int i=0;i<n;i++){
            int profit=rightmax[i]-leftmax[i];
            maxi=max(maxi,profit);
        }
        if(maxi<0)maxi=0;
        return maxi;
    }
};