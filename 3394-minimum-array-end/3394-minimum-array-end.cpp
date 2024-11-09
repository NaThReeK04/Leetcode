class Solution {
public:
       long long minEnd(int n, int x) {
        long long anding=x;
        for(int i=1;i<n;i++){
            anding=(anding+1)|x;
        }
        return anding;
    }
};
