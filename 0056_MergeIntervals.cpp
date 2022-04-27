class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(), intervals.end());
		
		int l = intervals[0][0], r = intervals[0][1];
		for(int i = 1; i < intervals.size(); i++) {
			if(intervals[i][0] <= r) r = max(r, intervals[i][1]);
			else {
				ans.push_back({l, r}); //当下一个为新区间时，将上一个加入结果集
				l = intervals[i][0], r = intervals[i][1];
			}
		}
		ans.push_back({l, r}); //由于加入结果集的是上一个，故最后一个需要额外添加
		return ans;
    }
};