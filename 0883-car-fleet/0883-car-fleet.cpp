class Solution {
public:
    static bool compare(pair<int,double>&a,pair<int,double>&b){
        return a.first>b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>>cars;
        for(int i=0;i<n;i++){
            double dis=(double)(target-position[i])/speed[i];
            cars.push_back(make_pair(position[i],dis));
        }
        sort(cars.begin(),cars.end(),compare);
        int fleet=0;
        double time=0.0;
        for(int i=0;i<cars.size();i++){
            if(cars[i].second>time){
                fleet++;
                time=cars[i].second;
            }

        }
        return fleet;
    }
};