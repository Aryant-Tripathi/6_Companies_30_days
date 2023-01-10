class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        
        int Acount = 0;
        for(int i = 0; i < n; i++)
        {
            if(secret[i] == guess[i])
            {
                Acount++;
            }
        }
        
        unordered_map<char, int> mp;
        for(char c: secret)
            mp[c]++;
        
        int Bcount = 0;
        for(char c: guess)
        {
            if(mp.find(c) != mp.end())
            {
                mp[c]--;
                if(mp[c] >= 0)
                {
                    Bcount++;
                }
            }
        }
        
        return to_string(Acount) + "A" + to_string(Bcount - Acount) + "B";
    }
};