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
    void preorder(TreeNode* root,vector<int>&ans,vector<int>&level,int i){
        if(root==NULL)return;
        if(level[i]!=1){
            ans.push_back(root->val);
            level[i]=1;

        }
        preorder(root->right,ans,level,i+1);
        preorder(root->left,ans,level,i+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        vector<int>level(51,0);
        preorder(root,ans,level,0);
        return ans;
    }
};