class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minv = INT_MAX;
        int ans = 0;
        for (int price : prices) {
            ans = max(ans, price - minv);
            minv = min(minv, price);
        }
        return ans;
    }
};