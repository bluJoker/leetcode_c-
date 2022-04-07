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
    void recoverTree(TreeNode* root) {
        TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *prev = nullptr; 
        dfs(root, mistake1, mistake2, prev);
        if (mistake1 && mistake2) 
            swap(mistake1->val, mistake2->val);   
    }

    void dfs(TreeNode* root, TreeNode* &mistake1, TreeNode* &mistake2, TreeNode* &prev) {
        if(!root) return;
        dfs(root->left, mistake1, mistake2, prev);
        if(prev && root->val < prev->val) {
            if(!mistake1) mistake1 = prev, mistake2 = root;
            else mistake2 = root;
        }
        prev = root;
        dfs(root->right, mistake1, mistake2, prev);
    }
};

/**
 * dfs函数参数使用的是c++中的指针引用。
 * 因为我们需要修改的是传入的mistake1指针本身的值，所以此处需要传引用 &mistake1，且类型为指针。
 * 故参数为TreeNode* &mistake1。
 */