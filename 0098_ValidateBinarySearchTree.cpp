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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX); //测试用例root->val可能是INT_MAX，故防止越界边界需要使用long long
    }

    bool dfs(TreeNode* root, long long minv, long long maxv) {
        if(root == nullptr) return true;
        if(root->val <= minv || root->val >= maxv) return false;
        return dfs(root->left, minv, root->val) && dfs(root->right, root->val, maxv);
    }
};

/**
 * 通过自上而下传递最小值和最大值来解决这个问题。在迭代遍历整个树的过程中，利用逐渐变窄的范围来检查各个节点。
 * 首先从(LONG_LONG_MIN, LONG_LONG_MAX)开始，根结点显然落在其中。然后处理左子树，检查这些节点是否落在(minv, root->val)范围内。
 * 接下来处理右子树，检查这些节点是否落在(root->val, maxv)范围内。
 * 
 * 之后，继续以此遍历整棵树。进入左子树时，更新max。进入右子树，更新minv。只要有任一节点不能通过检查，则停止并返回false。
*/


//方法2：也可以自下而上
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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root)[0];
    }

    //[0]:以root为根结点的树是否是搜索树(1是，0不是)
	//[1][2]:以root为根结点的树的最小值和最大值
    vector<int> dfs(TreeNode* root) {
        vector<int> ans({1, root->val, root->val});
        if(root->left) {
            auto t = dfs(root->left);
            if(!t[0] || t[2] >= root->val) ans[0] = 0;
            ans[1] = min(t[1], ans[1]);
            ans[2] = max(t[2], ans[2]);
        }
        if(root->right) {
            auto t = dfs(root->right);
            if(!t[0] || t[1] <= root->val) ans[0] = 0;
            ans[1] = min(t[1], ans[1]);
            ans[2] = max(t[2], ans[2]);
        }
        return ans;
    }
};


//方法3：中序遍历序列是否有序
//TODO: