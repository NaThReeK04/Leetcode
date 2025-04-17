class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string universal="";
        for(int i=0;i<strs[0].size();i++){
            string temp=strs[0].substr(0,i+1);
            bool found=true;
            for(int j=0;j<strs.size();j++){
                string temp2=strs[j].substr(0,i+1);
                if(temp.size()>strs[j].size()||temp!=temp2){
                    found=false;
                    break;
                }
            }
            if(!found)break;
            universal=temp;
        }
        return universal;
    }
};