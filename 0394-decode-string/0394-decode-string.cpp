class Solution {
public:
    string decodeString(string s) {
        stack<int> repeatStack;     // Stack to store repetition counts
        stack<string> stringStack;  // Stack to store the string that existed
        int num = 0 ;    // Stores the current number
        string curr = "";   // Stores the string we are currently building

        for(char ch : s)
        {
            if(isdigit(ch))
                num = num*10 + (ch - '0');

            // Save current state before entering '['
            else if (ch=='[')
            {
                repeatStack.push(num);
                stringStack.push(curr);

                num = 0;
                curr = "";
            }
            else if(ch==']')
            {
                int repeat = repeatStack.top();
                repeatStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                string temp = "";
                for(int i = 0; i<repeat ; i++)
                    temp+=curr;
                curr = prev + temp;
            }
            // Add normal characters
            else 
                curr += ch;
        }
        return curr;
    }
};