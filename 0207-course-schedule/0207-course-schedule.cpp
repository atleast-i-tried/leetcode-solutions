class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& grid) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;

        for(auto it: grid) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();;
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return numCourses == ans.size();
    }
}; 