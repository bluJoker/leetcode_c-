class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
		while (i > 0 && nums[i - 1] >= nums[i]) {
			i--;
		}
        if (i > 0) {
            int j = i;
            while (j < nums.size() && nums[j] > nums[i - 1]) j++;
            swap(nums[i - 1], nums[j - 1]);
        }
		// reverse的两种情形：(1)i<=0[i=-1]表示原序列逆序，则reverse即为下一个排列
		// (2)原序列非逆序，则reverse部分
		reverse(nums.begin() + i, nums.end());
    }
};