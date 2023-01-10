class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> mp;
        
        while(j < n)
        {
            mp[s[j]]++;
            
            while(i < n && mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
            {
                ans += n - j;
                mp[s[i]]--;
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};