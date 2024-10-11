class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for(int i = 0; i < 10001; i++){
            availableRooms.push(i);
        }

        vector<vector<int>> timesWithIndex;
        int ind = 0;
        for(vector<int> time: times){
            timesWithIndex.push_back({time[0], time[1], ind++});
        }

        sort(timesWithIndex.begin(), timesWithIndex.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> usedRooms;

        for(vector<int> time: timesWithIndex){

            int start = time[0];
            int end = time[1];
            int ind = time[2];

            while(!usedRooms.empty() && usedRooms.top().first <= start){
                pair<int, int> p = usedRooms.top();
                usedRooms.pop();
                availableRooms.push(p.second);
            }

            int room = availableRooms.top();
            availableRooms.pop();

            if(ind == targetFriend){
                return room;
            }

            usedRooms.push({end, room});
        }

        return -1;
    }
};