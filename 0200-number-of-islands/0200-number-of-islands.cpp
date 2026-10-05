class Solution {
public:

    int n, m;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool check(int i, int j) {
        if(i >= 0 && j >= 0 && i < n && j < m) {
            return true;
        }
        return false;
    }

    vector<pair<int,int>> neighb(int i, int j) {

        vector<pair<int,int>> store;

        for(int dir = 0; dir < 4; dir++) {

            int ni = i + dx[dir];
            int nj = j + dy[dir];

            if(check(ni, nj)) {
                store.push_back({ni, nj});
            }
        }

        return store;
    }

    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        vis[i][j] = 1;

        for(auto a : neighb(i, j)) {

            int x = a.first;
            int y = a.second;

            if(!vis[x][y] && grid[x][y] == '1') {
                dfs(x, y, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(!vis[i][j] && grid[i][j] == '1') {

                    dfs(i, j, vis, grid);

                    cnt++;
                }
            }
        }

        return cnt;
    }
};