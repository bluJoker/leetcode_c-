class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = l + 1ll + r >> 1; //l+r也可能会越界
            if (mid <= x / mid) l = mid; //写成mid*mid<=x可能会越界
            else r = mid - 1; 
        }
        return l;
    }
};