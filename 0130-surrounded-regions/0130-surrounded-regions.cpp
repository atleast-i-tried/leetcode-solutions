class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& dirs, int& m, int& n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
        board[i][j] = '#';
        for (int k = 0; k < 4; k++) {  
            dfs(i + dirs[k][0], j + dirs[k][1], board, dirs, m, n);
        }
    }

    void solve(vector<vector<char>>& board) {        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) {
                    dfs(i, j, board, dirs, m, n);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {  
                    board[i][j] = 'O'; 
                }
            }
        }
    }
};
