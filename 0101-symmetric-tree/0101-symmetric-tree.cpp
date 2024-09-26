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
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both nodes are null, they are symmetric
        if (left == nullptr && right == nullptr) return true;
        // If one is null and the other is not, they are not symmetric
        if (left == nullptr || right == nullptr) return false;
        // Check values and recurse on the left and right children
        return (left->val == right->val) &&
               isMirror(left->right, right->left) && // Check outer children
               isMirror(left->left, right->right);   // Check inner children
    }

    bool isSymmetric(TreeNode* root) {
        // A null tree is symmetric
        if (root == nullptr) return true;
        // Check if the left and right subtrees are mirrors
        return isMirror(root->left, root->right);
    }
};


