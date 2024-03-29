/**
 * 
 * https://leetcode.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        using std::swap;
        
        if (!root)
            return nullptr;
        
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        
        swap(root->left, root->right);
        
        return root;
    }
};
