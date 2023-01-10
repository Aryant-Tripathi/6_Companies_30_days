class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        
        if(is_sorted(arr.begin(), arr.end()) == true)
            return 0;
        
        int front = 0, back = n - 1;
        
        vector<int> copy = arr;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != copy[i])
            {
                front = i;
                break;
            }
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(arr[i] != copy[i])
            {
                back = i;
                break;
            }
        }
        
        if(back < front) return 0;
        
        return back - front + 1;
    }
};