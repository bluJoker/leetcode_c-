class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size() - 1, j = num2.size() - 1, t = 0;
        
        while (i >= 0 || j >= 0 || t) {
            if (i >= 0) t += num1[i] - '0';
            if (j >= 0) t += num2[j] - '0';
            ans += to_string(t % 10);
            t /= 10;
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};