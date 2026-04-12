#include<iostream>
using namespace std;
class Solution {

public:
    bool possible(vector<int>& arr,long long val,int m,int k)
    {
        //val is array of mid
        long long b=0;
        int count=0;

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=val)
            {
                count++;
            }
            else
            {
                b+=count/k;
                count=0;
            }
        }
        b+=count/k;
        return b >= m;
    }

     int minDays(vector<int>& bloomDay, int m, int k) {
        //flower bloomDay[i] blooms on the bloomDay[i]
        //maeaning [2,3,2,4,2] on the 2nd day three flowers will be bloomed [x,3,x,4,x]
        //to make the bouqet we always choose adjacednt flowers m=2,k=2
        //[x,x]then next [x,x]
        //after the min day each day will be valid so we have to find min only 
        //range starts from min(arr) to max(arr) 
        
        int n=bloomDay.size();
        if (1LL * m * k > n) return -1;
        
        //now using the part of binary search
       
       long long l= *min_element(bloomDay.begin(),bloomDay.end());
        long long h= *max_element(bloomDay.begin(),bloomDay.end());
       
        while(l<=h)
        {
            long long mid = l + (h - l) / 2;
            if(possible(bloomDay,mid,m,k))
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;



        
        
    }



};
int main()
{
    Solution s1;
    vector<int>arr={7,7,7,7,12,7,7};
    cout<<s1.minDays(arr,2,3);
    
}