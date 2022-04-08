class Solution {
public:
    vector<int> p;
    int find(int u) {
        if (u != p[u]) p[u] = find(p[u]);
        return p[u];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i; //节点从1到n
        
        for (auto &e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) return e;
            else p[a] = b;
        }
        return {};
    }
};

/**
 * 无向图找环：使用并查集
 * 从前往后判断是否成环，成环的就是数组 edges 中最后出现的边
*/