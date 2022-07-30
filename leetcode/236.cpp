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
    vector<TreeNode*> getPath(TreeNode* n, int target) {
        vector<TreeNode*> ret = vector<TreeNode*>();
        if (n == NULL) {
            return ret;
        }
        if (n->val == target) {
            ret.push_back(n);
            return ret;
        }
        ret = getPath(n->left, target);
        if (ret.size() > 0) {
            ret.push_back(n);
            return ret;
        }
        ret = getPath(n->right, target);
        if (ret.size() > 0) {
            ret.push_back(n);
            return ret;
        }
        return ret;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP = getPath(root, p->val);
        vector<TreeNode*> pathQ = getPath(root, q->val);
        TreeNode* ret;
        for (int i = 0; i < pathP.size() && i < pathQ.size(); i++) {
            if (pathP[pathP.size() - 1 - i]->val == pathQ[pathQ.size() - 1 - i]->val) {
                ret = pathP[pathP.size() - 1 - i];
            }
        }
        return ret;
    }
};
