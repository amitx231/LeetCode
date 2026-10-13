// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x<2)
//             return x;
        
//         for(long long i = 1; i<=x; i++)
//         {
//             if(i*i>x)
//                 return i-1;
//         }
//         return x;
//     }
// };


// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x<2)
//             return x;
//         long long i = 1;
//         while(i*i<=x)
//         {
//             i++;
//         }
//         return i - 1;
//     }
// };


class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        long long low = 1;
        long long high = x;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid<x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};