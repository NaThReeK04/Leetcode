class Solution
{
    public:
        long long dividePlayers(vector<int> &skill)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int n = skill.size();
            if (n == 2)
            {
                return skill[0] *skill[1];
            }
            unordered_map<int, int> mpp;
            for (int i = 0; i < n; i++)
            {
                mpp[skill[i]]++;
            }
            long long chem = 0;
            int num = (*max_element(skill.begin(), skill.end())) + (*min_element(skill.begin(), skill.end()));
            for (int i = 0; i < n; i++)
            {
                int req = num - skill[i];
                if (mpp[skill[i]] != 0)
                {
                    if (mpp.find(req) != mpp.end())
                    {
                        int pro = skill[i] *req;
                        chem += pro;
                        mpp[skill[i]]--;
                        mpp[req]--;
                    }
                }
            }
            for (auto &it: mpp)
            {
                if (it.second != 0)
                {
                    return -1;
                }
            }
            return chem;
        }
};