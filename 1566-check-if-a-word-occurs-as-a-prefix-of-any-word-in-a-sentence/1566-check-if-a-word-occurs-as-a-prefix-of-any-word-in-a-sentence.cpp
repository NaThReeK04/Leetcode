class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=searchWord.length();
        int m=sentence.length();
        int left=0;
        int right=n-1;
        int spacecount=0;
        string sub1=sentence.substr(left,n);
        if(sub1==searchWord)return 1;
        for(int i=0;i<n;i++){
            char ch=sentence[i];
            if(isblank(ch))spacecount++;
        }
        left++;
        right++;
        while(left<=right&&right<m){
            string sub=sentence.substr(left,n);
            if(sub==searchWord&&isblank(sentence[left-1]))return spacecount+1;
            if(isblank(sentence[right]))spacecount++;
            left++;
            right++;
        }
        return -1;

    }
};