class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        string curr = "";

        for(int i = 0 ; i <=path.size() ; i++)
        {
            // '/' means the current directory name is complete
            if(i==path.size() || path[i]=='/')
            {
                // Ignore empty parts and "."
                if(curr=="" || curr==".")
                {

                }
                // ".." means go to the parent directory
                else if(curr=="..")
                {
                    if(!s.empty())
                        s.pop();
                }
                // Normal directory name
                else 
                    s.push(curr);
                // reset and start reading the next directory
                curr = "";
            }
            else
                curr+=path[i];
        }
        string ans = "";

        while(!s.empty())
        {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        // if stack is empty, we are at root
        return ans.empty() ? "/" : ans;
    }
};