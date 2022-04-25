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
    bool isSymmetric(TreeNode* root) {
		return helper(root, root);
    }
	
	bool helper(TreeNode* p, TreeNode* q) {
		if(!p || !q) return !p && !q;
		if(p->val != q->val) return false;
		return helper(p->left, q->right) && helper(p->right, q->left);
	}
};

// 迭代
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if(!root) return true;
		queue<TreeNode*> q1, q2;
		q1.push(root), q2.push(root);
		while(!q1.empty() && !q2.empty()) {
			TreeNode *p1 = q1.front(), *p2 = q2.front();
            q1.pop(), q2.pop();
			if(!p2 && !p2) continue; //!
			if((!p1 && p2) || (!p2 && p1)) return false;
			if(p1->val != p2->val) return false;
			q1.push(p1->left); //不能写成非空才插入队列: if(p1->left) q1.push(p1->left);
			q1.push(p1->right);
			q2.push(p2->right);
			q2.push(p2->left);
		}
		return true;
    }
};