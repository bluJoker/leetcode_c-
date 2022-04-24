// 使用位运算优化
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int u, int state) {
        if (u == nums.size()) {
            ans.push_back(path);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (!(state >> i & 1)) {
                    path.push_back(nums[i]);
                    dfs(nums, u + 1, state + (1 << i));
                    path.pop_back();
                }
            }
        }
        
    }
};