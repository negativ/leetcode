/**
 * 
 * https://leetcode.com/problems/increasing-order-search-tree/
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        
        prev = &dummy;
        
        traverse(root);
        
        return dummy.right;
    }
    
private:
    void traverse(TreeNode* n) {
        if (!n)
            return;
        
        traverse(n->left);
               
        prev = prev->right = n;
        prev->left = nullptr;
        
        traverse(n->right);
    }
    
    TreeNode* prev;    
};
