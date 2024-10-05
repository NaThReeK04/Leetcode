/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void inorder(TreeNode *root, vector<int> &ans)
        {
            if (root == NULL) return;
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    bool findTarget(TreeNode *root, int k)
    {

        vector<int> ans;
        inorder(root, ans);
        if (ans.size() == 1)
        {
            return false;
        }
        unordered_map<int, int> mpp;
        for (int i = 0; i < ans.size(); i++)
        {
            mpp[ans[i]]++;
        }
        bool found = false;
        for (int i = 0; i < ans.size(); i++)
        {
            int tar = k - ans[i];
            if (ans[i] == tar)
            {
                if (mpp.find(tar) != mpp.end() && mpp[tar] >= 2)
                {
                    return true;
                }
            }
            else
            {
                if (mpp.find(tar) != mpp.end())
                {
                    return true;
                }
            }
        }
        return false;
    }
};