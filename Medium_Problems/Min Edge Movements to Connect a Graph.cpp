//Problem: Min Edge Movements to Connect a Graph
//Topic: Disjoint Set Union (DSU) / Union-Find
//Pattern: Medium

class Solution {
  public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;   // redundant edge

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;

        return true;
    }
    int minEdgesReq(int n, vector<vector<int>>& edges) {
       int m = edges.size();

        // A connected graph with n vertices needs at least n-1 edges
        if (m < n - 1)
            return -1;

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto &e : edges) {
            if (unite(e[0], e[1])) {
                components--;
            }
        }

        return components - 1; 
        
    }
};
