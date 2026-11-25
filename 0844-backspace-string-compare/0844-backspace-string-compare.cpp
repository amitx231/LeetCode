class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>text1;
        stack<char>text2;
        for(char ch : s)
        {
            if( ch == '#')
            {
                if(!text1.empty())
                    text1.pop();
            }
            else
                text1.push(ch);
        }
        for(char ch : t)
        {
            if( ch == '#')
            {
                if(!text2.empty())
                    text2.pop();
            }
            else
                text2.push(ch);
        }
        if(text1.size()!=text2.size())
            return false;
        while(!text1.empty() && !text2.empty())
        {
            if(text1.top()!=text2.top())  
                return false;
            text1.pop();
            text2.pop();

        }
        return text1.empty() && text2.empty();
    }
};