class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
            while (s.length() <= k)
            {
                string result = "";
                for (char c: s)
                {
                    if (isalpha(c))
                    {
                        if (c == 'z')
                        {
                            result += 'a';
                        }
                        else
                        {
                            result += c + 1;
                        }
                    }
                }
                s+=result;
            }
            return s[k-1];
    }
};