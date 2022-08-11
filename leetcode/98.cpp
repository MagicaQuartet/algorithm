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
    int prv;
    bool init = false;
public:
    bool isValidBST(TreeNode* root) {
        if (root->left != nullptr) {
            if (!isValidBST(root->left)) {
                return false;
            }
        }
        if (!init) {
            prv = root->val;
            init = true;
        }
        else {
            if (root->val <= prv) {
                return false;
            }
            prv = root->val;
        }
        if (root->right != nullptr) {
            if (!isValidBST(root->right)) {
                return false;
            }
        }
        return true;
    }
};
