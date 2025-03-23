class Solution {
public:
    using ll = long long;
    using p = pair<ll, int>; 
    const int MOD = 1e9 + 7; 

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<ll> dist(n, LLONG_MAX);  
        vector<int> path(n, 0);
        
        pq.push({0, 0});
        dist[0] = 0;
        path[0] = 1;

        while (!pq.empty()) {
            auto [curDist, u] = pq.top();
            pq.pop();

            if (curDist > dist[u]) continue;  

            for (auto [v, weight] : adj[u]) {
                ll newDist = curDist + weight;
                
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    path[v] = path[u];  
                    pq.push({dist[v], v});
                } else if (newDist == dist[v]) {
                    path[v] = (path[v] + path[u]) % MOD;  
                }
            }
        }
        
        return path[n - 1];
    }
};
