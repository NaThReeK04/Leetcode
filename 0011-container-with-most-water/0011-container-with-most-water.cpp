class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxi=INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            int area=(j-i)*min(height[i],height[j]);
            maxi=max(maxi,area);
            if(height[i]<height[j])i++;
            else if(height[j]<height[i])j--;
            else{
                i++;
                j--;
            }
        }
        return maxi;
    }
};