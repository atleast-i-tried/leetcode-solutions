

class Solution {
public:
    int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    int permutationsCnt(string temp) {
        int freqproduct = 1;
        unordered_map<char, int> mp;
        for (char ch : temp) {
            mp[ch]++;
        }

        for (auto [key, value] : mp) {
            freqproduct *= factorial(value);
        }

        return factorial(temp.size()) / freqproduct;
    }

    void helper(int index, string temp, string tiles, vector<string>& ans, int& cnt) {
        if (!temp.empty()) {
            cnt += permutationsCnt(temp);
            cout << temp << " " << cnt << endl;
        }

        for (int i = index; i < tiles.size(); i++) {
            if (i > index && tiles[i] == tiles[i - 1]) continue;

            temp += tiles[i];
            helper(i + 1, temp, tiles, ans, cnt);
            temp.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        int cnt = 0;
        vector<string> ans;
        string temp;
        helper(0, temp, tiles, ans, cnt);
        return cnt;
    }
};