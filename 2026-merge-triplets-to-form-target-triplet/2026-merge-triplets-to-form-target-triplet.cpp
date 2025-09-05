class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0];
        int y = target[1];
        int z = target[2];
        int fx = 0;
        int fy = 0;
        int fz = 0;
        for (auto t : triplets) {
            int first = t[0];
            int second = t[1];
            int third = t[2];
            if (first <= x && second <= y && third <= z) {
                if (first == x)
                    fx = 1;
                if (second == y)
                    fy = 1;
                if (third == z)
                    fz = 1;
            }
        }
        return fx && fy && fz;
    }
};