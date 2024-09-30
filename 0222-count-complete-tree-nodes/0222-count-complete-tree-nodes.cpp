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
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL)return;
        ans.push_back(root->val);
        inorder(root->left,ans);
        inorder(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return 1;
        vector<int>ans;
        inorder(root,ans);
        return ans.size();
        
    }
};