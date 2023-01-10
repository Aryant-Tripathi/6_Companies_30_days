class Solution {
public:
    int evalRPN(vector<string>& arr) {
        int n = arr.size();
        stack<long long> s;
        
        for(string str: arr)
        {
            if(str == "+" || str == "-" || str == "*" || str == "/")
            {
                long long two = s.top();
                s.pop();
                
                long long one = s.top();
                s.pop();
                
                long long res;
                if(str == "+")
                {
                    res = one + two;
                }
                else if(str == "-")
                {
                    res = one - two;
                }
                else if(str == "*")
                {
                    res = one * two;
                }
                else if(str == "/")
                {
                    res = one / two;
                }
                
                s.push(res);
            }
            else
            {
                s.push(stoll(str));
            }
        }
        
        return s.top();
    }
};