// dp: O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};


// 贪心: O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); i++) {
            if (stk.empty() || stk.back() < nums[i]) 
				stk.push_back(nums[i]);
            else 
                *lower_bound(stk.begin(), stk.end(), nums[i]) = nums[i];
        }
        return stk.size();
    }
};

// 输出具体方案：
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        vector<int> g(n);
        int ans = 0, k = 0;
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        g[i] = j; //使用g数组记录从哪一个点转移过来的
                    }       
                }
            }
            if (ans < f[i]) k = i; //记录最优解的下标
            ans = max(ans, f[i]);
        }
        for (int i = 0, len = f[k]; i < len; i++){ //最长序列长度为len。故循环len次即为倒叙方案
            cout << nums[k] << ' ';
            k = g[k];
        }

        return ans;
    }
};