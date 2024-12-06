class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mpp;
        for(int i=0;i<banned.size();i++){
            mpp[banned[i]]++;
        }
        int count=0;
        int currsum=0;
        for(int i=1;i<=n;i++){
            if(mpp.find(i)==mpp.end())currsum+=i;
            if(currsum<=maxSum&&mpp.find(i)==mpp.end()){
                count++;
            }
            if(currsum>maxSum)break;
        }
        return count;
    }
};