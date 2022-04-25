// dp
// f[i]表示以i结尾的连续子数组的最大和
// 划分规则：该区间长度>=2 | 区间长度为1，即f[i]=max(nums[i], f[i-1]+nums[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for (auto x : nums) {
            sum = max(sum + x, x);
            ans = max(ans, sum);
        }
        return ans;
    }
};


//延伸——获取最大序列的起始和结束位置
//将以这个元素结尾的的最大子序列的位置找出来，然后每次比较最大值的时候更新一下最大值的位置就行了
public int maxSubArrayPosition(int[] nums) {
    if (nums == null) {
        return 0;
    }

    int start = 0;
    int end = 0;
    int subStart = 0;
    int subEnd = 0;
    int max = nums[0];    // 全局最大值
    int subMax = nums[0];  // 前一个子组合的最大值
    for (int i = 1; i < nums.length; i++) {
        if (subMax > 0) {
            // 前一个子组合最大值大于0，正增益，更新最后元素位置
            subMax = subMax + nums[i];
            subEnd++;
        } else {
            // 前一个子组合最大值小于0，抛弃前面的结果，更新当前最大值位置
            subMax = nums[i];
            subStart = i;
            subEnd = i;
        }
        // 计算全局最大值，更新位置，将全局最优解的位置更新
        if (subMax > max) {
            max = subMax;
            start = subStart;
            end = subEnd;
        }
    }
	
    System.out.println("[" + start + ","+ end +"]");
    return max;
}
//链接：https://leetcode-cn.com/problems/maximum-subarray/solution/zheng-li-yi-xia-kan-de-dong-de-da-an-by-lizhiqiang/