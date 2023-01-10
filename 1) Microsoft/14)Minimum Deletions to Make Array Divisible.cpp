class Solution {
public:
    int minOperations(vector<int>& arr, vector<int>& arr2) {
        sort(arr.begin(), arr.end());
        
        int Ourgcd = 0;
        
        for(auto i : arr2)
        {
            Ourgcd = __gcd(Ourgcd, i);
        }
        
        int ans = 0;
        
        int n = arr.size();
        for(int i = 0;i < arr.size();i++)
        {
            if(arr[i] == Ourgcd|| Ourgcd % arr[i]==0)
            {
                break;
            }
            else 
            {
                ans++;
                n--;
            }
        }
        
        if(n ==  0) return -1;
            
        return ans;
    }
};