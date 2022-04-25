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
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		vector<int> path;
		if(!root) return ans;
		queue<TreeNode*> q;
		q.push(root);
		while(q.size()) {
			for(int i = q.size() - 1; i >= 0; i--) {
				TreeNode* t = q.front();
				q.pop();
				path.push_back(t->val);
				if(t->left) q.push(t->left);
				if(t->right) q.push(t->right);
			}
			ans.push_back(path);
			path.clear();
		}
		return ans;
    }
};


// 递归：使用index参数维护层数信息
class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;
    vector<vector<int>> levelOrder(TreeNode* root) {
		helper(root, 0);
		return ans;
    }
	void helper(TreeNode* root, int index) {
		if(!root) return;
		
		//当遍历到新层时，向结果集添加vector
		if(ans.size() == index) ans.push_back(vector<int>{}); 
		
		ans[index].push_back(root->val);
		if(root->left) helper(root->left, index + 1);
		if(root->right) helper(root->right, index + 1);
	}
};
