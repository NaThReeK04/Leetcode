class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum=accumulate(apple.begin(),apple.end(),0);
        int currsum=0;
        for(int i=0;i<capacity.size();i++){
            currsum+=capacity[i];
            if(currsum>=sum)return i+1;
        }
        return capacity.size();
    }
};