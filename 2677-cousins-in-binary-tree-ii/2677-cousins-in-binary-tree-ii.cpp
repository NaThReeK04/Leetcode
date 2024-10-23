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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> currentLevel;
            int levelsum=0;

            for (int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();
                currentLevel.push_back(it); 

                auto node = it;
               
                if (node->left) {
                    q.push(node->left);
                    levelsum+=node->left->val;
                }
                if (node->right) {
                    q.push(node->right);
                    levelsum+=node->right->val;
                }
            }

            for (auto &it : currentLevel) {
                auto node = it;
                int i=levelsum;
                if(node->left)i-=node->left->val;
                if(node->right)i-=node->right->val;
                if(node->left)node->left->val=i;
                if(node->right)node->right->val=i;      
            }
        }
        root->val=0;
        return root;
    }
};

















