/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, TreeNode* root1) {
        if (root == nullptr && root1 == nullptr) return true;
        if (root == nullptr || root1 == nullptr) return false;
        return (root->val == root1->val && 
                check(root->left, root1->left) && 
                check(root->right, root1->right));
    }
    TreeNode* inorder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        if (root == p || root == q) {
            return root;
        }

        TreeNode* left = inorder(root->left, p, q);
        TreeNode* right = inorder(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return (left != nullptr) ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return inorder(root, p, q);
    }
};
