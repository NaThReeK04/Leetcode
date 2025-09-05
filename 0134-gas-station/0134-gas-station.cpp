class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalfuel = 0, totalgas = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalfuel += cost[i];
            totalgas += gas[i];
        }
        if (totalfuel > totalgas)
            return -1;
        int currentfuel = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            currentfuel += (gas[i] - cost[i]);
            if (currentfuel < 0) {
                start = i + 1;
                currentfuel = 0;
            }
        }
        return start;
    }
};