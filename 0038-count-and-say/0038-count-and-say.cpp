class Solution {
public:
    string countAndSay(int n) {
        string temp="1";
        if(n==1)return temp;
        for(int i=2;i<=n;i++){
            int count=1;
            string temp2="";
            for(int j=1;j<temp.size();j++){
                if(temp[j]==temp[j-1]){
                     count++;
                }
                else if(temp[j]!=temp[j-1]){
                    temp2+=to_string(count);
                    temp2+=temp[j-1];
                    count=1;
                }
            }
            temp2+=to_string(count);
            temp2+=temp.back();
            temp=temp2;
        }
        return temp;
    }
};