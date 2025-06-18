class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", n, 0);
        return res;
    }

private:
    void backtrack(vector<string>& res, string current, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(current);
            return;
        }

        if (close > 0) {
            backtrack(res, current + ")", open, close - 1);
        }

        if (open > 0) {
            backtrack(res, current + "(", open - 1, close + 1);
        }
    }
};
