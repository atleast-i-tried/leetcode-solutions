class Solution {
public:
    bool coloring(vector<vector<int>>& adj, vector<int>& color, int node, int colour) {
        color[node] = colour;

        for(auto it: adj[node]) {
            if(color[it] == -1) {
                if(coloring(adj, color, it, !colour) == false) return false;
            } else if (color[it] == colour) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(coloring(adj, color, i, 0) == false) return false;
            }
        }
        return true;
    }
};