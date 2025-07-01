class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<ll> distance(n, LLONG_MAX);
        vector<int> path(n, 0);

        pq.push({0, 0});
        distance[0] = 0;
        path[0] = 1;

        while(!pq.empty()) {
            auto [tillDist, node] = pq.top();
            pq.pop();

            for(auto [v, cost]: adj[node]) {
                if(distance[v] > tillDist + cost) {
                    distance[v] = tillDist + cost;
                    path[v] = path[node];
                    pq.push({distance[v], v});
                } else if(distance[v] == tillDist + cost) {
                    path[v] = (path[v] + path[node]) % MOD;
                }
            }
        }
        return path[n - 1];
    }
};