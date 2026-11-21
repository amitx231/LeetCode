class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string s;
        for(int x : num)
        {
            // Remove larger previous digits
            while(!s.empty() && x<s.back() && k>0)
            {
                s.pop_back();
                k--;
            }
            s.push_back(x); //push current digit
            // edge cases.....
            // case 1: if k > 0 means remaining numbers are in increasing order
            
        }
        while(k>0)
        {
            s.pop_back();
            k--;
        }
        // case 2 : when ans contains leading zero .. 
        // Remove leading zeros
        int i = 0;
        while(i<s.size() && s[i]=='0')
            i++;
        s = s.substr(i);
        if(s.empty())
            return "0";
        else
            return s;
    }
};