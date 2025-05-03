class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int maxi1=INT_MIN;
        int max_ele1;
        int maxi2=INT_MIN;
        int max_ele2;
        unordered_map<int,int>mpp1,mpp2;
        for(int i=0;i<tops.size();i++){
            mpp1[tops[i]]++;
            if(mpp1[tops[i]]>maxi1){
                maxi1=max(maxi1,mpp1[tops[i]]);
                max_ele1=tops[i];
            }
            mpp2[bottoms[i]]++;
            if(mpp2[bottoms[i]]>maxi2){
                maxi2=max(maxi2,mpp2[bottoms[i]]);
                max_ele2=bottoms[i];
            }
            
        }
        int count=0;
        if(maxi1>maxi2){
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=max_ele1&&bottoms[i]==max_ele1){
                    count++;
                }else if(tops[i]!=max_ele1&&bottoms[i]!=max_ele1){
                    count=-1;
                    break;
                }
            }
        }else if(maxi2>maxi1){
            for(int i=0;i<bottoms.size();i++){
                if(bottoms[i]!=max_ele2&&tops[i]==max_ele2){
                    count++;
                }else if(bottoms[i]!=max_ele2&&tops[i]!=max_ele2){
                    count=-1;
                    break;
                }
            }
        }else{
            int count2=0;
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=max_ele1&&bottoms[i]==max_ele1){
                    count2++;
                }else if(tops[i]!=max_ele1&&bottoms[i]!=max_ele1){
                    count2=-1;
                    break;
                }
            }
            int count3=0;
            for(int i=0;i<bottoms.size();i++){
                if(bottoms[i]!=max_ele2&&tops[i]==max_ele2){
                    count3++;
                }else if(bottoms[i]!=max_ele2&&tops[i]!=max_ele2){
                    count3=-1;
                    break;
                }
            }
            count=(count2>count3)?count2:count3;

        }
        return count;
    }
};