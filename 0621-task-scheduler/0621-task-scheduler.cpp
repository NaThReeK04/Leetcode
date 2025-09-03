class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequency of each task (since only uppercase A-Z, 26 slots)
        vector<int> freq(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        // Step 2: Use a max heap to always pick the task with the highest remaining count
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push(freq[i]);
        }
        
        int time = 0;
        
        // Step 3: Process tasks in cycles of (n+1) slots
        // Because at most one task of the same type can be scheduled within n cool-down
        while (!pq.empty()) {
            vector<int> temp;  // to store updated counts after this round
            
            // Try to execute up to (n+1) tasks in this cycle
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int num = pq.top();
                    pq.pop();
                    num--;  // one occurrence of this task is executed
                    temp.push_back(num);
                }
            }
            
            // Push remaining counts back into heap
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] != 0)
                    pq.push(temp[i]);
            }
            
            // If heap still has tasks, we must have taken full (n+1) time
            // Otherwise, only add the number of tasks executed in this last cycle
            if (pq.empty()) {
                time += temp.size();
            } else {
                time += n + 1;
            }
        }
        return time;
    }
};
