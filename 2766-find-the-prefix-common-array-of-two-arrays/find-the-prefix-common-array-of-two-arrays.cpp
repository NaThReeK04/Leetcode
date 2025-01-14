class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>C;
        int n=A.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<=i;j++){
                auto it=find(A.begin(),A.begin()+i+1,B[j]);
                if(it!=A.begin()+i+1)count++;
            }
            C.push_back(count);
        }
        return C;
    }
};