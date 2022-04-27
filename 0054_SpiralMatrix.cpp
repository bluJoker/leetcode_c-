class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		int n = matrix.size();
		if(!n) return ans;
		int m = matrix[0].size();
		
		vector<vector<int>> st(n, vector<int>(m, false));
		int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
		int x = 0, y = 0, j = 0;

		for(int i = 0; i < n * m; i++) {
			st[x][y] = true;
			ans.push_back(matrix[x][y]);
			int a = x + dx[j], b = y + dy[j];
			if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
				j = (j + 1) % 4;
				a = x + dx[j], b = y + dy[j];
			}
			x = a, y = b;	
		}
		return ans;
    }
};