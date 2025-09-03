class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push(freq[i]);
        }
        
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int num = pq.top();
                    pq.pop();
                    num--;
                    temp.push_back(num);
                }
            }
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] != 0)
                    pq.push(temp[i]);
            }
            if (pq.empty()) {
                time += temp.size();
            } else {
                time += n + 1;
            }
        }
        return time;
    }
};