/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//方法一：递归
//时间复杂度O(N)：其中N为二叉树节点数；最差情况下，需要递归遍历树的所有节点。
//空间复杂度O(N)：最差情况下，递归深度达到N，系统使用O(N)大小的额外空间。

//后序遍历，当遇到节点p或q时返回，故根据返回值得出pq是否在子树中。
//第一次碰到节点p,q在节点root的异侧时[包括root==p或q的情况]，节点root即为最近公共祖先，则向上返回root 。

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(!l && !r) return nullptr; //(1)
        if(!l) return r; //(3)
        if(!r) return l; //(4)
        return root; //(2) if(left != NULL and right != NULL)
    }
};

/**
 *返回值：根据left和right，可展开为四种情况；

    (1)当left和 right 同时为空：说明root的左/右子树中都不包含 p,q，返回null；
    (2)当left和 right 同时不为空：说明p,q分列在root的 异侧（分别在左/右子树），因此root为最近公共祖先，返回 root；
    (3)当left为空 ，right不为空：p,q都不在root的左子树中，直接返回 right。具体可分为两种情况：
        p,q其中一个在root的右子树中，此时right指向p（假设为p）；
        p,q两节点都在root的右子树中，此时的right指向最近公共祖先节点 ；
    (4)当 left不为空，right为空：与情况 3. 同理;

链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/
*/