class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        vector<vector<int>> adj(numCourses);

        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indegree(numCourses, 0);

        for(auto it: edges) {
            indegree[it[1]]++;
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]) {
                if(--indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        for(auto it: indegree) {
            if(it != 0) return false;
        }
    
        return true;
    }
};