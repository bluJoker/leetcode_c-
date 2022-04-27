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
	int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
		dfs(root);
		return ans;
    }
	
	// 返回从root向下走的最大值: root->val + max(left, right)。
	// 而不是root->val + left + right，因为同一个节点在一条路径序列中至多出现一次。 
	int dfs(TreeNode* root) {
		if(!root) return 0;
		int left = max(0, dfs(root->left)); //负数则不走，不走为0
		int right = max(0, dfs(root->right));
		ans = max(ans, root->val + left + right);
		return root->val + max(left, right);
	}
};