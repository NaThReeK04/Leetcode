class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)return {{1}};
        else if(numRows==2)return {{1},{1,1}};
       
            vector<vector<int>>ans;
            ans.push_back({{1}});
            ans.push_back({{1,1}});
            for(int i=2;i<numRows;i++){
                vector<int>temp;
                temp.push_back(1);
                for(int j=0;j<ans[i-1].size()-1;j++){
                    int num=ans[i-1][j]+ans[i-1][j+1];
                    temp.push_back(num);
                }
                temp.push_back(1);
                ans.push_back(temp);
            }

        return ans;
    }
};