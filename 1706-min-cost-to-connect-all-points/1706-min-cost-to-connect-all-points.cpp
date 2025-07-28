class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n, 0);
        
        int sum = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            if (vis[node.second]) {
                continue;
            }
            
            vis[node.second] = 1;
            sum += node.first;
            
            for (auto it : adj[node.second]) {
                if (!vis[it.first]) {
                    pq.push({it.second, it.first});
                }
            }
        }
        return sum;
    }
};