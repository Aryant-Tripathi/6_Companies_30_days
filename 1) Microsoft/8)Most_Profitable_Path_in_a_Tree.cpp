class Solution {
public:
    bool dfs(int node, int time, unordered_map<int, int>& path, vector<bool>& vis,
             vector<int> adj[])
    {
        path[node] = time;
        vis[node] = true;
        
        if(node == 0)
            return true;
        
        for(auto& it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, time + 1, path, vis, adj))
                    return true;
            }
        }
        
        path.erase(node);
        return false;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        vector<int> adj[n + 1];
        
        for(int i = 0; i < n; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // it stores path of bob
        unordered_map<int, int> path;
        vector<bool> vis(n + 1, false);
        
        dfs(bob, 0, path, vis, adj);
        
        int ans = INT_MIN;
        queue<vector<int>> q;
        
        // node, time, amount
        q.push({0, 0, 0});
        
        for(int i = 0; i <= n; i++)
            vis[i] = false;
        
        while(!q.empty())
        {
            int node = q.front()[0];
            int time = q.front()[1];
            int cost = q.front()[2];
            q.pop();
            
            vis[node] = true;
            
            if(path.find(node) == path.end())
            {
                cost += amount[node];
            }
            else if(time < path[node])
            {
                cost += amount[node];
            }
            else if(time == path[node])
            {
                cost += amount[node] / 2;
            }
            
            if(adj[node].size() == 1 && node != 0)
                ans = max(ans, cost);
            
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    q.push({it, time + 1, cost});
                }
            }
        }
        
        return ans;
    }
};