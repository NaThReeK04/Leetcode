class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char t : tasks) freq[t]++;

        // last execution time for each task (initialize to -inf)
        vector<int> lastExec(26, -100000);

        int time = 0;
        int remaining = tasks.size();

        while(remaining > 0) {
            char bestTask = '#';
            // find best task to execute at this time
            for(auto &p : freq) {
                char task = p.first;
                int count = p.second;
                if(count > 0 && time - lastExec[task - 'A'] > n) {
                    if(bestTask == '#' || freq[task] > freq[bestTask]) {
                        bestTask = task;
                    }
                }
            }

            if(bestTask == '#') {
                // no task can be scheduled -> idle
                time++;
            } else {
                // schedule bestTask
                freq[bestTask]--;
                lastExec[bestTask - 'A'] = time;
                time++;
                remaining--;
            }
        }
        return time;
    }
};
