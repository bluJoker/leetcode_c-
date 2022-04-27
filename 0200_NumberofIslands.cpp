// dfs
class Solution {
public:
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	int n, m;
    int numIslands(vector<vector<char>>& g) {
        n = g.size();
		if(!n) return 0;
		m = g[0].size();
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				if(g[i][j] == '1') {
					dfs(g, i, j);
					ans++;
				}
			}
		return ans;
    }
	
	void dfs(vector<vector<char>>& g, int x, int y) {
		g[x][y] = '0';
		for(int i = 0; i < 4; i++) {
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= n || b < 0 || b >= m) continue;
			if(g[a][b] == '0') continue;
			//g[a][b] = '0'; 此处修改也可以
			dfs(g, a, b);
		}
	}
};

// bfs
class Solution {
public:
	int n, m;
    int numIslands(vector<vector<char>>& g) {
        n = g.size();
		if(!n) return 0;
		m = g[0].size();
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				if(g[i][j] == '1') {
					bfs(g, i, j);
					ans++;
				}
			}
		return ans;
    }
	
	void bfs(vector<vector<char>>& g, int x, int y) {
		int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
		//不能在此处修改。因为dfs每次进入下次递归都会在此处修改。
		//但bfs只会到一次这里。后面会在while处一直循环。
		//g[x][y] = '0'; 
		queue<pair<int, int>> q;
		q.push({x, y});
		while(!q.empty()) {
			auto t = q.front();
			q.pop();
			for(int i = 0; i < 4; i++) {
				int a = t.first + dx[i], b = t.second + dy[i];
				if(a < 0 || a >= n || b < 0 || b >= m) continue;
				if(g[a][b] == '0') continue;
				g[a][b] = '0';
				q.push({a, b});
			}
		}
	}
};