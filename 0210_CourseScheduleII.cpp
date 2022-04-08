class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>> g(n); //使用二维数组表示邻接表
        vector<int> d(n); //入度
        
        for(auto& e : edges) {
            int b = e[0], a = e[1];
            g[a].push_back(b);
            d[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!d[i]) q.push(i);
        }
        
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            ans.push_back(t);

            for (int i : g[t]) {
                if (--d[i] == 0) q.push(i);
            }
        }
        if (ans.size() < n) ans = {};
        return ans;
    }
};

/**
 * 使用二维数组vector<vector<int>>表示邻接表，但其中只能说明两点之间是否有边，权重没有存储。
 * 在leetcode中写代码比较方便。
*/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int m = prerequisites.size();
        vector<int> h(n, -1);
        vector<int> d(n, 0); //入度
        vector<int> e(m, 0), ne(m, 0);
        int idx = 0;

        for (int i = 0; i < m; i++) {
            int b = prerequisites[i][0], a = prerequisites[i][1];
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
            d[b]++;    
        }

        vector<int> q(n, 0);
        int hh = 0, tt = -1;
        for (int i = 0; i < n; i++) {
            if (!d[i]) q[++tt] = i;
        }
        
        while (hh <= tt) {
            int t = q[hh++];
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                if (--d[j] == 0) q[++tt] = j;
            }
        }
        if (tt == n - 1)
            for (int i = 0; i < n; i++) ans.push_back(q[i]);
        return ans;
    }
};

/**
 * 传统算法竞赛中，使用数组模拟单链表表示邻接表，速度快效率高。
*/