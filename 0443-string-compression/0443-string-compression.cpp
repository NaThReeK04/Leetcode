class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1)return 1;
        int count=1;
        string temp="";
        for(int i=1;i<chars.size();i++){
            if(chars[i-1]!=chars[i]){
                if(count>1){
                    temp+=chars[i-1];
                    temp+=to_string(count);
                    count=1;
                }else if(count==1){
                    temp+=chars[i-1];
                }
            }
            else if(chars[i-1]==chars[i]){
                count++;
            }
        }
        if(count>1){
            temp+=chars.back();
            temp+=to_string(count);
         }else if(count==1){
            temp+=chars.back();
          }
        vector<char>ans;
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
        chars=ans;
        return chars.size();   
        
    }
};