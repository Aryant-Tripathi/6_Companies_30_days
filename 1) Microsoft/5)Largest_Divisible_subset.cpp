class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        if(n == 0)
            return ans;
        
        // Finding LIS
        sort(arr.begin(), arr.end());
        int mx = 1;
        vector<int> dp(n+1, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[i] % arr[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    if(mx < dp[i])
                    {
                        mx = dp[i];
                    }
                }
            }
        }
        
        // pushing answer
        int prev = -1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(dp[i] == mx && (prev % arr[i] == 0 || prev == -1))
            {
                ans.push_back(arr[i]);
                mx = mx - 1;
                prev = arr[i];
            }
        }
        
        return ans;
        
    }
};