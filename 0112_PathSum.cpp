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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;   
		
		// 注意递归终止条件(到叶子节点)
        if(!root->left && !root->right) return root->val == targetSum;

        return hasPathSum(root->left, targetSum - root->val) 
            || hasPathSum(root->right, targetSum - root->val);
    }
};