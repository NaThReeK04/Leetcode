class Solution {
public:
    long long flowerGame(int n, int m) {
        int feven=0;
        int fodd=0;
        int seven=0;
        int sodd=0;
        for(int i=1;i<=n;i++){
            if(i%2==0)feven++;
            else fodd++;
        }
        for(int j=1;j<=m;j++){
            if(j%2==0)seven++;
            else sodd++;
        }
        long long ans=(1LL*feven*sodd)+(1LL*fodd*seven);
        return ans;
    }
};