class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {

        const long long MOD = 1e9 + 7;

        // {neighbor, time}
        vector<list<pair<int, int>>> g(n);

        // Build graph
        for (auto road : roads) {

            int u = road[0];
            int v = road[1];
            int time = road[2];

            // Bidirectional
            g[u].push_back({v, time});
            g[v].push_back({u, time});
        }

        // dist[i] = shortest time to reach i
        vector<long long> dist(n, LLONG_MAX);

        // ways[i] = number of shortest ways to reach i
        vector<long long> ways(n, 0);

        // {distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        // Starting point
        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            // Ignore outdated entry
            if (d > dist[u])
                continue;

            for (auto [v, time] : g[u]) {

                long long newDist = d + time;

                // Found a shorter path
                if (newDist < dist[v]) {

                    dist[v] = newDist;

                    // All shortest paths to v currently come through u
                    ways[v] = ways[u];

                    pq.push({newDist, v});
                }

                // Found another shortest path
                else if (newDist == dist[v]) {

                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};