class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.empty() || s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size(); j++) {
            if (g[i] <= s[j]) {
                ans++;
                i++;
            }
        }
        return ans;
    }
};

/** 
 * 1、从小到大排序g和s。当饼干s[j] >= 孩子g[i]，将该饼干分配给该孩子，i++, j++。
 * 当s[j] < g[i]，表示该饼干小了，此时需要看后面的饼干能否分配给该孩子，j++。
 * 2、也可以不用ans记录分配数，最后的孩子数i即为所求。
 */