class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        if(s.length()==0)
            return "";
        
        //lps dp array
        vector<int> dp = {0}; // this hold the prefix which is also a suffix ending at index i
                                //index 1 2 3  4  5 6 7
                               // eg:   a a a  b  a a a  [ignore space]
                               // dp:  [0,1,2, 0, 1,2,3 ]
        
        //create lps array
        int i=0;
        for(int j=1; j< n; j++)
        {
            while(i && s[i] != s[j])
            {
                i = dp[i-1];
            }
            
            i += s[i]==s[j];
            dp.push_back(i);
        }
        return s.substr(0,dp[n-1]);
    }
};