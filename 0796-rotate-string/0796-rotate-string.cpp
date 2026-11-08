class Solution {
public:
    vector<int>buildLPS(string s)
    {
        vector<int>lps(s.size(),0);
        int pre = 0;
        int suf = 1;
        while(suf<s.size())
        {
            if(s[pre]==s[suf])
            {
                lps[suf]=pre+1;
                suf++, pre++;
            }
            else
            {
                if(pre==0)
                    lps[suf++]=0;
                else
                    pre = lps[pre-1];
            }
        }
        return lps;
    }
    bool KMP(string text, string pattern)
    {
        if(pattern.empty() || pattern.size()>text.size())
            return false;
        vector<int>lps = buildLPS(pattern);
        int first = 0, second=0;
        while(first<text.size() && second<pattern.size())
        {
            if(text[first]==pattern[second])
            {
                first++, second++;
                if(second == pattern.size())
                    return true;

            }
            else
            {
                if(second==0)
                    first++;
                else
                    second = lps[second-1];
            }
            
        }
        return false;
    }
    bool rotateString(string s, string goal) {
        // if goal is cyclic rotation of s,
        // then goal must be present inside (s+s)
        if(s.size()!=goal.size())
            return false;
        string text = s + s;
        if(KMP(text,goal))
            return true;
        return false;
    }
};