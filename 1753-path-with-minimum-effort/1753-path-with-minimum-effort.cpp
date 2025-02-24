class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX)); 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        pq.push({0, {0, 0}});
        efforts[0][0] = 0;

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int x = node.second.first;
            int y = node.second.second;
            int currEffort = node.first;

            for (int i = 0; i < 4; i++) {
                int a = x + dirs[i][0];
                int b = y + dirs[i][1];

                if (a >= 0 && a < m && b >= 0 && b < n) {
                    int newEffort = max(currEffort, abs(heights[x][y] - heights[a][b])); 
                    if (newEffort < efforts[a][b]) {
                        efforts[a][b] = newEffort;
                        pq.push({newEffort, {a, b}});
                    }
                }
            }
        }
        return efforts[m - 1][n - 1];
    }
};