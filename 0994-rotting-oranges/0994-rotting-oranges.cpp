class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Put all rotten oranges into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int t = 0;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while(!q.empty()) {

            int s = q.size();
            bool rotten = false;

            for(int k = 0; k < s; k++) {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int r = 0; r < 4; r++) {

                    int x = i + dx[r];
                    int y = j + dy[r];

                    if(x >= 0 && y >= 0 && x < n && y < m
                       && grid[x][y] == 1) {

                        grid[x][y] = 2;
                        fresh--;

                        q.push({x, y});
                        rotten = true;
                    }
                }
            }

            if(rotten) {
                t++;
            }
        }

        if(fresh > 0) {
            return -1;
        }

        return t;
    }
};