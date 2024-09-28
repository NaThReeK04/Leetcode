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
    // Helper function to find the path from root to a given node 'p' and store the path in 'pa'.
    bool path(TreeNode* root, TreeNode* p, vector<int>& pa) {
        if (root == nullptr) return false; // Base case: root is null
        
        pa.push_back(root->val); // Add current node to the path
        
        // Check if the current node is the target node
        if (root->val == p->val) return true;

        // Recursively search in left and right subtrees
        if (path(root->left, p, pa) || path(root->right, p, pa)) return true;

        pa.pop_back(); // If not found, remove the node from path and backtrack
        return false;
    }

    // Function to find the last common element between two paths
    int findLastCommonElement(vector<int>& pa, vector<int>& qa) {
        int lastCommon = -1;
        int i = 0;
        
        // Traverse both vectors until the values start to differ
        while (i < pa.size() && i < qa.size() && pa[i] == qa[i]) {
            lastCommon = pa[i];
            i++;
        }
        
        return lastCommon; // Return the last common value
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> pa; // Path to node p
        vector<int> qa; // Path to node q
        
        // Get paths from root to nodes p and q
        path(root, p, pa);
        path(root, q, qa);
        
        // Find the last common node value in both paths
        int lcaValue = findLastCommonElement(pa, qa);

        // Find and return the actual TreeNode* corresponding to the LCA value
        return findNode(root, lcaValue);
    }
    
    // Helper function to find a node by its value in the tree
    TreeNode* findNode(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) return root;

        TreeNode* leftSearch = findNode(root->left, val);
        if (leftSearch) return leftSearch;

        return findNode(root->right, val);
    }
};
