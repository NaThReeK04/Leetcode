/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        TreeNode* searchBST(TreeNode *root, int value)
        {
            if (root == nullptr || root->val == value)
            {
                return root;
            }
            if (value < root->val)
            {
                return searchBST(root->left, value);
            }
            return searchBST(root->right, value);
        }
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root->left == NULL || root->right == NULL) return root;
        vector<int> ans1;
        vector<int> ans2;
        TreeNode *curr = root;
        if (curr->val == p->val)
        {
            ans1.push_back(curr->val);
        }
        while (curr)
        {
            if (curr->val > p->val)
            {
                ans1.push_back(curr->val);
                curr = curr->left;
            }
            else if (curr->val < p->val)
            {
                ans1.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                ans1.push_back(curr->val);
                curr = NULL;
            }
        }
        TreeNode *curr2 = root;
        if (curr2->val == q->val)
        {
            ans1.push_back(curr2->val);
        }
        while (curr2)
        {
            if (curr2->val > q->val)
            {
                ans2.push_back(curr2->val);
                curr2 = curr2->left;
            }
            else if (curr2->val < q->val)
            {
                ans2.push_back(curr2->val);
                curr2 = curr2->right;
            }
            else
            {
                ans2.push_back(curr2->val);
                curr2 = NULL;
            }
        }
        int target = 0;
        int n = ans1.size();
        int m = ans2.size();
        if (n == 1)
        {
            target = ans1[0];
        }
        else if (m == 1)
        {
            target = ans2[0];
        }
        else
        {
            if (n <= m)
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    bool q = false;
                    for (int j = m - 1; j >= 0; j--)
                    {
                        if (ans1[i] == ans2[j])
                        {
                            target = ans2[j];
                            q = true;
                            break;
                        }
                    }
                    if (q == true)
                    {
                        break;
                    }
                }
            }
            else
            {
                for (int i = m - 1; i >= 0; i--)
                {
                    bool l = false;
                    for (int j = n - 1; j >= 0; j--)
                    {
                        if (ans2[i] == ans1[j])
                        {
                            target = ans1[j];
                            l = true;
                            break;
                        }
                    }
                    if (l == true)
                    {
                        break;
                    }
                }
            }
        }
        TreeNode *temp = searchBST(root, target);
        return temp;
    }
};