// 方法1：最小堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            if (pq.size() < k) pq.push(num);
            else if (pq.top() < num){
                pq.pop();
                pq.push(num);  
            }
        }
        return pq.top();
    }
};

// 方法2：快排partition - 递归
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;
        return helper(nums, 0, nums.size() - 1, k);
    }
	
    int helper(vector<int>& nums, int l, int r, int k) {
        int q = partition(nums, l, r);
        if (q == nums.size() - k) 
            return nums[q];
        else 
            return q < nums.size() - k ? helper(nums, q + 1, r, k) : helper(nums, l, q - 1, k);
    }

    int partition(vector<int>& nums, int lo, int hi) {
        int k = nums[lo];
        int i = lo + 1, j = hi;
        while (1) {
            while (i <= hi && nums[i] < k) i++;
            while (j > lo && nums[j] > k) j--;
            if (i >= j) break;
            swap(nums[i], nums[j]);
            i++, j--;
        }
        swap(nums[lo], nums[j]);
        return j;
    }
};

// 方法2'：快排partition - 迭代
int partition(vector<int>& nums, int l, int r) {
    int i = l + 1, j = r;
    int key = nums[l];
    while (true) {
        while (i <= r && nums[i] < key)
            i++;
        while (j >= l + 1 && nums[j] > key)
            j--;
        if (i >= j)
            break;
        swap(nums[i], nums[j]);
        i++, j--;
    }
    swap(nums[l], nums[j]);
    return j;
}

int helper(vector<int>& nums, int l, int r, int k) {
    while (l <= r) {
        int j = partition(nums, l, r);
        if (j == nums.size() - k)
            return nums[j];
        else if (j < nums.size() - k)
            l = j + 1;
        else
            r = j - 1;
    }
    return -1;
}

int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty() || k > nums.size()) {
        return -1;
    }
    int l = 0, r = nums.size() - 1;
    return helper(nums, l, r, k);
}


/**
 * 如果要保证快排解法达到O(n)，最好使用排序前随机化
 *   inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]); //题解划分元素取得是最后一个。我用的是第一个元素。
        return partition(a, l, r);
    }
*/