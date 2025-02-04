class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int a[201], b[201];
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    a[i] = 1;
                    b[j] = 1;
                }
            }
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (a[i] == 1 || b[j] == 1) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};