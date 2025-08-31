class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>>pq;
        for(int i=0;i<points.size();i++){
            double val=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push(make_pair(val,points[i]));
        }
        int num=0;
        while(num!=k){
            auto m=pq.top();
            pq.pop();
            ans.push_back(m.second);
            num++;
        }
        return ans;
    }
};