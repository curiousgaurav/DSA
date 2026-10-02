class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int,int>>> pq;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        dis[0][0] = 0;

        pq.push({0, {0, 0}});

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while(!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int diff = -cur.first;
            int i = cur.second.first;
            int j = cur.second.second;

            if(i == n-1 && j == m-1) {
                return diff;
            }

            for(int k = 0; k < 4; k++) {

                int newr = i + dx[k];
                int newc = j + dy[k];

                if(newr >= 0 && newr < n &&
                   newc >= 0 && newc < m) {

                    int d = abs(heights[i][j] -
                                heights[newr][newc]);

                    int ne = max(diff, d);

                    if(ne < dis[newr][newc]) {

                        dis[newr][newc] = ne;

                        pq.push({-ne, {newr, newc}});
                    }
                }
            }
        }

        return 0;
    }
};