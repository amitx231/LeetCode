class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>idx;
        // Find invalid parentheses 
        for(int i = 0; i<s.size() ; i++)
        {
            if(s[i]=='(')
                idx.push(i);
            else if(s[i]==')')
            {
                if(idx.empty())
                    s[i]='*'; // invalid parenthesis mark as invalid
                else
                    idx.pop();
            }
        }
        // // Mark unmatched opening brackets
        while(!idx.empty())
        {
            s[idx.top()]='*';
            idx.pop();
        }
        string ans="";
        for(char c : s)
        {
            if(c!='*')
                ans+=c;
        }
        return ans;
        
    }
};