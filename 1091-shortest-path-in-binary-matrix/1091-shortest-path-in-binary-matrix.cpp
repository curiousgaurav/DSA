class Solution {
public:

    vector<pair<int,int>> neighbour(int i, int j, int n) {
        vector<pair<int,int>> v;

        for(int x = i-1; x <= i+1; x++) {
            for(int y = j-1; y <= j+1; y++) {

                if(x >= 0 && x < n &&
                   y >= 0 && y < n &&
                   !(x == i && y == j)) {

                    v.push_back({x, y});
                }
            }
        }

        return v;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // {row, column, distance}
        queue<tuple<int,int,int>> q;

        q.push({0, 0, 1});
        grid[0][0] = 1;

        while(!q.empty()) {

            auto [i, j, dis] = q.front();
            q.pop();

            if(i == n-1 && j == n-1)
                return dis;

            for(auto p : neighbour(i, j, n)) {

                int x = p.first;
                int y = p.second;

                if(grid[x][y] == 0) {

                    grid[x][y] = 1;

                    q.push({x, y, dis + 1});
                }
            }
        }

        return -1;
    }
};