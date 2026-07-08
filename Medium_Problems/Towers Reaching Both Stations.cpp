//Problem: Towers Reaching Both Stations
//Topic: Graph + DFS / BFS + Matrix Traversal + Flood Fill + Reverse Graph Traversal
//Pattern: Medium

class Solution {
  public:
  int n, m;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& mat,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;

            if (vis[ni][nj])
                continue;

            // Reverse flow
            if (mat[ni][nj] >= mat[i][j])
                dfs(ni, nj, mat, vis);
        }
    }
    int countCoordinates(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<bool>> P(n, vector<bool>(m, false));
        vector<vector<bool>> Q(n, vector<bool>(m, false));

        // Station P : top row
        for (int j = 0; j < m; j++)
            if (!P[0][j])
                dfs(0, j, mat, P);

        // Station P : left column
        for (int i = 0; i < n; i++)
            if (!P[i][0])
                dfs(i, 0, mat, P);

        // Station Q : bottom row
        for (int j = 0; j < m; j++)
            if (!Q[n-1][j])
                dfs(n-1, j, mat, Q);

        // Station Q : right column
        for (int i = 0; i < n; i++)
            if (!Q[i][m-1])
                dfs(i, m-1, mat, Q);

        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (P[i][j] && Q[i][j])
                    ans++;

        return ans;
        
    }
};
