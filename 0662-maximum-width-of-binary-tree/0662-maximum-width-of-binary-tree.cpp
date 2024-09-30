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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int mini=q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front().first;
                int curr_id=q.front().second-mini;
                q.pop();
                if(i==0)first=curr_id;
                if(i==n-1)last=curr_id;
                if(temp->left!=NULL)q.push({temp->left,(long long)curr_id*2+1});
                if(temp->right!=NULL)q.push({temp->right,(long long)curr_id*2+2});

            }
            ans=max(ans,(last-first)+1);

        }
        return ans;
    }
};