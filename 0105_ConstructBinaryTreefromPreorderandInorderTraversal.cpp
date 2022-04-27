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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
        if (inorder.size() != n) return nullptr;
		return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }
	
	TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
		if(pl > pr) return nullptr;
		TreeNode* root = new TreeNode(preorder[pl]);
		int len = 0;
		for(int i = il; i <= ir; i++) {
			if(inorder[i] == preorder[pl]) break;
			len++;
		}
		root->left = dfs(preorder, inorder, pl + 1, pl + len, il, il + len - 1);
		root->right = dfs(preorder, inorder, pl + len + 1, pr, il + len + 1, ir);
		return root;
	}
};