class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a;
        int b;
        int n=grid.size();
        vector<int>ash(pow(n,2)+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ash[grid[i][j]]+=1;
            }
        }
        for(int i=1;i<=(n*n);i++){
            if(ash[i]==2)a=i;
            if(ash[i]==0)b=i;
        }
        return {a,b};
    }
};