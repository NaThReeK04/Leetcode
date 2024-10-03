/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int countGoodNodes(TreeNode* root, int maxSoFar)
    {
        if (root == NULL)
            return 0;
        int good = 0;
        if (root->val >= maxSoFar)
            good = 1;
        maxSoFar = max(maxSoFar, root->val);
        good += countGoodNodes(root->left, maxSoFar);
        good += countGoodNodes(root->right, maxSoFar);

        return good;
    }

    int goodNodes(TreeNode* root)
    {
        return countGoodNodes(root, root->val);
    }
};
