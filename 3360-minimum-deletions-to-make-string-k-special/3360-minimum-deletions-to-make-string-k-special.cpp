class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        unordered_map<char, int> mp;
        int n = word.size();
        for (char ch : word)
            mp[ch]++;
        vector<int> freq;
        for (auto x : mp)
            freq.push_back(x.second);
        sort(freq.begin(), freq.end());
        int mx = freq.back(), ans = INT_MAX;
        for (int i = 1; i <= mx; i++)
        {
            int cnt = 0;
            for (int j = 0; j < freq.size(); j++)
            {
                if (freq[j] > i + k)
                    cnt += freq[j] - i - k;
                else if (freq[j] < i)
                    cnt += freq[j];
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};