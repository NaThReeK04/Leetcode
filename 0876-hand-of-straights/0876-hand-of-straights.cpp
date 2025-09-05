class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mpp;
        if(hand.size()%groupSize!=0)return false;
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        while(!mpp.empty()){
            auto iter=mpp.begin();
            int num=iter->first;
            for(int i=0;i<groupSize;i++){
                int curr=num+i;
                if(mpp[curr]==0)return false;
                mpp[curr]--;
                if(mpp[curr]==0){
                    mpp.erase(curr);
                }
            }
        }
        return true;
    }
};