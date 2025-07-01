class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1},  {1, 0}, {1, 1}};
        int cnt = 1;

        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) { 
                auto node = q.front();
                q.pop();
                if (node.first == n - 1 && node.second == n - 1) {
                    return cnt;
                }
                for (int i = 0; i < 8; i++) {
                    int a = node.first + dir[i][0];
                    int b = node.second + dir[i][1];
                    if (a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == 0) {
                        q.push({a, b});
                        grid[a][b] = 1;
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};