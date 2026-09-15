class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        for(int i = 0 ; i<=m-n ; i++)
        {
            int j = 0;
            // Compare needle with current substring
            while(j<n && haystack[i+j]==needle[j])
                j++;
            if(n==j)
                return i;
        }
        return -1;
    }
};