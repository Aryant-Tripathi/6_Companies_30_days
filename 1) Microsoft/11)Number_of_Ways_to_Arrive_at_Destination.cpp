#define ll long long 
#define pll pair<ll, ll>

class Solution {
public:
    const int mod = (1e9 + 7);
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pll> adj[n];
        
        for(auto &road: roads)
        {
            ll u = road[0];
            ll v = road[1];
            ll time = road[2];
            
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        
        vector<ll> dis(n, LONG_MAX);
        dis[0] = 0;
        
        priority_queue<pll, vector<pll>, greater<>> pq;
        pq.push({dis[0], 0});
        
        vector<ll> ways(n);
        ways[0] = 1;
        
        while(!pq.empty())
        {
            pll curr = pq.top();
            pq.pop();
            
            ll currCost = curr.first;
            ll currNode = curr.second;
            
            for(auto &it: adj[currNode])
            {
                ll nextNode = it.first;
                ll nextCost = it.second;
                
                if(dis[nextNode] > currCost + nextCost)
                {
                    dis[nextNode] = currCost + nextCost;
                    ways[nextNode] = ways[currNode];
                    pq.push({dis[nextNode], nextNode});
                }
                else if(dis[nextNode] == currCost + nextCost)
                {
                    ways[nextNode] = (ways[currNode] + ways[nextNode]) % mod;
                }
            }
        }
        
        return ways[n - 1];
    }
};