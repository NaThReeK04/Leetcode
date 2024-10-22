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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>sums;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long long size=q.size();
            long long sum=0;
            for(long long i=0;i<size;i++){
                auto node=q.front();
                sum+=node->val;
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            sums.push_back(sum);
        }
        if(sums.size()<k)return -1;
        sort(sums.begin(),sums.end(),greater<long long>());
        long long  ans;
        for(long long i=0;i<sums.size();i++){
            if(i+1==k){
                ans= sums[i];
                break;
            }
        }
        return ans;

    }
};