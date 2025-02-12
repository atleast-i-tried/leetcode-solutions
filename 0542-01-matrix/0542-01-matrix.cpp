class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int a = node.first + dir[i][0];
                int b = node.second + dir[i][1];

                if(a >= 0 && b >= 0 && a < m && b < n && ans[a][b] == -1) {
                    q.push({a, b});
                    ans[a][b] = ans[node.first][node.second] + 1;
                }
            }
        }
        return ans;
    }
}; 