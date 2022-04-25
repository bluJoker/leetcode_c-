class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 1. 找分界点[最大值]
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        // 2. 判断target在哪一半区间
        if (nums[0] == target) return 0;
        else if (nums[0] > target) r = n - 1;
        else l = 0;

        // 3.两段都为单调递增，二分找target
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        if (nums[l] == target) return l;
        return -1;
    }
};

/**
 * 这道题要注意：如果面试官问你再旋转一次怎么做，做法还是一样的，无论旋转几次，最多只有2段递增序列

@M 旋转可以线性叠加，list.rotate(m+n) = list.rotate(m).rotate(n),可以看成只旋转一次

@M 自己手动试一下就会发现，只有两段是递增的

@Z 为什么
 */