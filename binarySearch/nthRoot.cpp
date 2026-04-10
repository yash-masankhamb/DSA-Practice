// Problem: Nth Root of a Number
// Platform: GFG / LeetCode
// Approach: Binary Search
// Time Complexity: O(log m * n)
// Space Complexity: O(1)
// Date: 11 April 2026
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long multiply(long long number,int n)
    {
        long long  ans=1;
        for(int i=0;i<n;i++)
        {
            ans*=number;
        }
        return ans;
    }
    int nthRoot(int n, int m) {
        // Code here
        //find nth root of m
        long long l=1;
        long long h=m;
        long long ans=-1;
           if(m==0)
            {
                return 0;
            }
        while(l<=h)
        {
            long long mid=(l+h)/2;
            long long a=multiply(mid,n);
         
            if(a==m)
            {
                return mid;
            }
         else if(a<m)
            {
                l=mid+1;
            }
            else{
                h=mid-1;
                
            }
        }
        return -1;
        
        
        
    }
};


int main() {
    Solution obj;
    
    int n = 3;
    int m = 27;

    cout << obj.nthRoot(n, m); // Output: 3

    return 0;
}


// Example:
// Input: n = 3, m = 27
// Output: 3

// Input: n = 2, m = 10
// Output: -1