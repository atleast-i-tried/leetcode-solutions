class Solution {
public:
    using p = pair<int, pair<int, int>>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> distance(n, INT_MAX);
        queue<p> q;

        q.push({src, {0, 0}});
        distance[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int cost = it.second.first;
            int steps = it.second.second;

            for (auto i : adj[node]) {
                if (distance[i.first] > cost + i.second && steps <= k) {
                    distance[i.first] = cost + i.second;
                    q.push({i.first, {distance[i.first], steps + 1}});
                }
            }
        }
        return distance[dst] == INT_MAX ? -1: distance[dst];
    }
};
