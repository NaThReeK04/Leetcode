class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        int n=temp.size();
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mpp;
        int count=1;
        for(int i=0;i<n;i++){
            auto it=mpp.find(temp[i]);
            if(it==mpp.end()){
                mpp[temp[i]]=count++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=mpp[arr[i]];
        }
        return arr;
    }
};