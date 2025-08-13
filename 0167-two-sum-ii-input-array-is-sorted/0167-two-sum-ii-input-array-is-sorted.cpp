class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        while(i<j){
            int s=numbers[i]+numbers[j];
            if(s==target)return {i+1,j+1};
            else if(s>target)j--;
            else i++;
        }
        return {-1,-1};
    }
};