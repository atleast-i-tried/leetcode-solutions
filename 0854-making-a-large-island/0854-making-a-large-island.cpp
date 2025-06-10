class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);  
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }

    void unionBySize(int a, int b) {
        int au = findUparent(a);
        int bu = findUparent(b);
        if(au == bu) return;

        if(size[au] > size[bu]) {
            parent[bu] = au;
            size[au] += size[bu];
        } else {
            parent[au] = bu;
            size[bu] += size[au];
        }
    }

    int getSize(int node) {
        return size[findUparent(node)];
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(n * m);
        vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(auto &dir : dirs) {
                        int nr = i + dir[0];
                        int nc = j + dir[1];
                        if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            ds.unionBySize(i * n + j, nr * n + nc);
                        }
                    }
                }
            }
        }

        int maxi = 0;
        bool zero = false;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    zero = true;
                    unordered_set<int> elements;
                    int size = 1;
                    for(auto &dir : dirs) {
                        int nr = i + dir[0];
                        int nc = j + dir[1];
                        if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int parent = ds.findUparent(nr * n + nc);
                            if(elements.find(parent) == elements.end()) {
                                size += ds.getSize(parent);
                                elements.insert(parent);
                            }
                        }
                    }
                    maxi = max(size, maxi);
                }
            }
        }

        if(!zero) return m * n;
        return maxi;        
    }
};
