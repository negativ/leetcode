/**
 * 
 * https://leetcode.com/problems/validate-binary-search-tree/
 * 
 */

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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        auto valid = true;
        TreeNode* prev = nullptr;

        traverse(root, [&](TreeNode* n) {
            if (!prev) {
                prev = n;

                return true;
            }

            if (!(prev->val < n->val)) {
                valid = false;
                return false;
            }
            
            prev = n;

            return true;
        });

        return valid;
    }
    
private:
    template <typename F>
    void traverse(TreeNode* node, F f) {
        if (!node)
            return;

        traverse(node->left, f);

        if (!f(node))
            return;

        traverse(node->right, f);
    } 
};
