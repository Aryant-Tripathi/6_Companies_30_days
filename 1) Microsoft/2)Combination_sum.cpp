class Solution {
public:
    int target;
    vector<vector<int>> ans;
    
    void solve(int i, int count, int sum, int k,
               vector<int>& arr, vector<int>& curr)
    {
        if(sum == target && count == k)
        {
            ans.push_back(curr);
            return;
        }
        
        if(i >= arr.size())
        {
            return;
        }
        
        if(sum > target || count > k)
        {
            return;
        }
        
        solve(i + 1, count, sum, k, arr, curr);
        
        curr.push_back(arr[i]);
        solve(i + 1, count + 1, sum + arr[i], k, arr, curr);
        curr.pop_back();
        
    }
    vector<vector<int>> combinationSum3(int k, int required_target) {
        ans.clear();
        target = required_target;
        
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> curr;
        int count = 0;
        int sum = 0;
        
        solve(0, count, sum, k, arr, curr);
        
        return ans;
    }
};