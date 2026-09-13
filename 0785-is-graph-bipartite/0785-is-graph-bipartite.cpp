class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, int c) {

        vis[node] = c;

        for(auto a : graph[node]) {

            if(vis[a] == -1) {
                if(!dfs(a, graph, vis, 1-c))
                    return false;
            }
            else if(vis[a] == vis[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, -1);

        for(int i = 0; i < n; i++) {

            if(vis[i] == -1) {
                if(!dfs(i, graph, vis, 0))
                    return false;
            }
        }

        return true;
    }
};