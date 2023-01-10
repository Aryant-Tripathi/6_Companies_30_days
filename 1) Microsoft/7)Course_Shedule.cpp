class Solution {
public:
    vector<int> adj[2001];
    int vis[2001];
    
    bool dfs(int node)
    {
        vis[node] = 1;
        
        for(int next: adj[node])
        {
            if(vis[next] == 0)
            {
                if(dfs(next) == true)
                    return true;
            }
            else
            {
                if(vis[next] == 1)
                    return true;
            }
        }
        
        vis[node] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        int n = numCourses;
        
        int size = arr.size();
        
        for(int i = 0; i < size; i++)
        {
            int a = arr[i][0];
            int b = arr[i][1];
            
            if(a == b)
                return false;
            
            adj[a].push_back(b);
        }
        
        bool ans = true;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(i) == true)
                {
                    ans = false;
                }
            }
        }
        
        return ans;
    }
};