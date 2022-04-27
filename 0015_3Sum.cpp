class Solution {
public:
	
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		if(nums.empty()) return ans;
		// 不可以包含重复，故利用排序避免重复答案
		sort(nums.begin(), nums.end());
		
		for (int i = 0; i < nums.size(); i++) {
			// 自左向右搜索，并且跳过重复值
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			
			// 排序后查找a, b, c满足条件a<b<c
            // 固定第一个元素a后，查找b+c=-a，由于数组已排序，转化为2Sum问题：Leetcode0001
			int l = i + 1, r = nums.size() - 1;
			while(l < r) {
				if (nums[l] + nums[r] == -nums[i]) {
					ans.push_back({nums[i], nums[l], nums[r]});
					// 由于可能存在多个解，我们需要继续移动指针寻找下一解，并且跳过重复值
					while (l < r && nums[l + 1] == nums[l]) l++;
					l++;
					while (l < r && nums[r - 1] == nums[r]) r--;
					r--;
				} else if(nums[l] + nums[r] < -nums[i]) {
					l++;
				} else r--;
			}
		}
		return ans;
    }
};