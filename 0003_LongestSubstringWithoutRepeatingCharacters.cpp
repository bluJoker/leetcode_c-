class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        unordered_map<char, int> m;
        for (int i = 0, j = 0; i < n; i++) {
            m[s[i]]++;
            // while (j < i && m[s[i]] > 1) m[s[j++]]--;
			// 不需要j<i。因为j>i时m为空，s[i]肯定为0了。
			while (m[s[i]] > 1) m[s[j++]]--;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};

/**
 * 子串：串中任意个连续的字符组成的子序列称为该串的子串（连续、连续、连续！重要的事情说三遍）
    备注：空串属于子串

2、串中字符均不相同：n个字符构成的字符串，假设每个字符都不一样，问有多少个子串
    答案：n(n+1)/2+1
    友情提示：每个字符均不相同
    解析：
        包含1个字符的子串共n个
        包含2个字符的子串共n-1个
        包含3个字符的子串共n-2个
        包含4个字符的子串共n-3个
        ......
        包含n个字符的子串共1个
        空串1个
        综上所述：子串个数共：1+2+3+。。。+n+1（空串）=n(n+1)/2+1
 *
*/