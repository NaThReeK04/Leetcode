class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            unordered_map<string, int> mpp;
            for (int i = 0; i < words.size(); i++)
            {
                mpp[words[i]]++;
            }
            int count = 0;
            bool odd = false;
            for (int i = 0; i < words.size(); i++)
            {
                string r = words[i];
                reverse(r.begin(), r.end());
                if (words[i] == r && mpp.find(r) != mpp.end())
                {
                    if (mpp[r] % 2 == 1)
                    {
                        count += (mpp[r] - 1);
                        odd = true;
                        mpp.erase(r);
                    }
                    else
                    {
                        count += mpp[r];
                        mpp.erase(r);
                    }
                }
                else if (mpp.find(words[i]) != mpp.end() && mpp[words[i]] > 0 && mpp.find(r) != mpp.end() && mpp[r] > 0)
                {
                    count += 2;
                    mpp[words[i]]--;
                    mpp[r]--;
                    if (mpp[words[i]] == 0) mpp.erase(words[i]);
                    if (mpp[r] == 0) mpp.erase(r);
                }
            }
            return (odd == true) ? ((count + 1) *2) : count * 2;
        }
};