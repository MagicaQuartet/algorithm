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
private:
    TreeNode* ans;
public:
    int search(TreeNode* node, TreeNode* p, TreeNode* q) {
        int ret = 0;
        if (node == NULL) {
            return ret;
        }
        if (node == p || node == q) {
            ret += 1;
        }
        ret += search(node->left, p, q) + search(node->right, p, q);
        if (ret == 2 && ans == NULL) {
            ans = node;
        }
        return ret;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        search(root, p, q);
        return ans;
    }
};