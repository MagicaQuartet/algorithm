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
    TreeNode* solve(TreeNode* n) {
        if (n == NULL) {
            return NULL;
        }
        TreeNode* right = n->right;
        n->right = NULL;
        if (n->left != NULL) {
            TreeNode* child = solve(n->left);
            n->right = child;
        }
        if (right != NULL) {
            TreeNode* child = solve(right);
            TreeNode* leaf = n;
            while (leaf->right != NULL) {
                leaf = leaf->right;
            }
            leaf->right = child;
        }
        n->left = NULL;
        return n;
    }

    void flatten(TreeNode* root) {
        solve(root);
        return;
    }
};
