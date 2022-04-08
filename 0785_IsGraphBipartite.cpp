// dfs
class Solution {
public:
    vector<int> color;
    vector<vector<int>> g;
    bool dfs(int u, int c) {
        color[u] = c;
        for (auto& v : g[u]) {
            if (color[v]) {
                if (color[v] == c) return false;
            } else if (!dfs(v, 3 - c)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int>(n, 0);
        g = graph;
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                if (!dfs(i, 1)) return false;
            }
        }
        return true;
    }
};

/**
 * 染色法判定二分图 
 * 0:没染过色 1:黑色 2:白色
 * 题目中给定的无向图不一定保证连通，因此我们需要进行多次遍历，直到每一个节点都被染色，或确定答案为 false 为止
*/


// bfs
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const int& v : graph[u]) {
                    if (color[v]) {
                        if (color[v] == color[u]) return false;
                    } else {
                        q.push(v);
                        color[v] = 3 - color[u];
                    }
                }
            }
        }
        return true;
    }
};