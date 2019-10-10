/**
 * 
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        
        int current = root->val;
        int sum = 0;
        
        dfs(root, current, sum);
        
        return sum;
    }
    
private:
    void dfs(TreeNode* root, int current, int &sum) {
        if (root->left == nullptr && root->right == nullptr) {
            sum += current;
            
            return;
        }
        
        current *= 10;
        
        if (root->left)
            dfs(root->left, current + root->left->val, sum);
        if (root->right)
            dfs(root->right, current + root->right->val, sum);
    }
};
