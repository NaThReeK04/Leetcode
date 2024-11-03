class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++){
            char temp=s[0];
            for(int j=0;j<n-1;j++){
                s[j]=s[j+1];;
            }
            s[n-1]=temp;
            if(s==goal){
                return true;
            }

        }
        return false;
    }
};