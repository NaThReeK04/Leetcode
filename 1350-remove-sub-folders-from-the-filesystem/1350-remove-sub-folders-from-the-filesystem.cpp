class Solution
{
    public:
        vector<string> removeSubfolders(vector<string> &folder)
        {
            vector<string> ans;
            unordered_map<string, int> mpp;
            sort(folder.begin(),folder.end());
            int n = folder.size();  
            for (int i = 0; i < n; i++)
            {
                int count1 = 1;
                int count2 = 0;
                string k = folder[i];
                for (int j = 1; j < k.length(); j++)
                {
                    if (k[j] != '/')
                    {
                        count1++;
                    }
                    else if (k[j] == '/')
                    {
                        break;
                    }
                }
                for (int l = k.length() - 1; l >= 0; l--)
                {
                    if (k[l] != '/')
                    {
                        count2++;
                    }
                    else if (k[l] == '/')
                    {
                        break;
                    }
                }
                count2++;
                bool ye=false;
                for(int t=count2;t<=folder[i].length();t+=count2){
                    string q = folder[i].substr(0, folder[i].length() - t);
                    if(mpp.find(q)!=mpp.end()){
                        ye=true;
                        break;
                    }
                }

                string s = folder[i].substr(0, folder[i].length() - count2);
                string p = folder[i].substr(0, count1);
                if (mpp.find(s) == mpp.end() && mpp.find(p) == mpp.end()&&ye==false)
                {
                    ans.push_back(folder[i]);
                    mpp[folder[i]] = 1;
                }
            }
            return ans;
        }
};