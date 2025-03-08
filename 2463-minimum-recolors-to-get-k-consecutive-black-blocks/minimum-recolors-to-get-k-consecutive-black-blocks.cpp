class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();
        int mini = INT_MAX;
        int whiteCount = 0;

        // Count 'W's in the first window of size k
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
                whiteCount++;
        }

        mini = min(mini, whiteCount);
        int i = 0, j = k;

        while (j < n)
        {
            if (blocks[i] == 'W')
                whiteCount--; 
            if (blocks[j] == 'W')
                whiteCount++; 

            mini = min(mini, whiteCount);
            i++, j++;
        }

        return mini;
    }
};
