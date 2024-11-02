class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.length();
        bool ye=true;
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(sentence[i]!=sentence[0]){
                    ye=false;
                }
            }else{
                if(isspace(sentence[i])){
                    if(sentence[i-1]!=sentence[i+1]){
                        ye=false;
                        break;
                    }
                }
            }
        }
        if(ye==false) return false;
        return true;
    }
};