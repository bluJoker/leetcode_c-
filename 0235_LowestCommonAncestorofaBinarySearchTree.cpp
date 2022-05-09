/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//题意：
//(1)所有节点的值都是唯一的。
//(2)p、q 为不同节点且均存在于给定的二叉搜索树中。


//3种情况：
//(1)p、q分别在root左右子树中。此时root即为最近公共祖先!
//(2)都在左子树中，最近公共祖先在左子树中，遍历左子树 (3)都在右子树中，遍历右子树

//递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val - p->val) * (root->val - q->val) <= 0) return root;
        if(root->val > p->val) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};

//迭代
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while(1) {
			if((root->val - p->val) * (root->val - q->val) <= 0) return root;
			if(root->val > p->val) root = root->left;
			else root = root->right;
		}
        return root;
    }
};