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
        
        deque<int> path;
        dfs(root, path);
        
        return ret;
    }
    
private:
    void dfs(TreeNode* root, deque<int>& path) {
        if (root->left == nullptr && root->right == nullptr) {
            ret += accumulate(rbegin(path), rend(path),
                              root->val,
                              [xpow{1}](auto acc, auto d) mutable { return acc + d * pow(10, xpow++); });
            
            return;
        }
        
        path.emplace_back(root->val);
        
        if (root->left)
            dfs(root->left, path);
        if (root->right)
            dfs(root->right, path);
        
        path.pop_back();
    }
    
    int ret;
};
