class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(num>0)
        {
            int rem = num % 10;
            ans+=rem;
            num = num/10;
            if(ans>9 && num==0)
            {
                num= ans;
                ans = 0;
            }
        }
        return ans;
    }
};