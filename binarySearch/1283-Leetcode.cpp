#include<iostream>
using namespace std;
class Solution {
public:
    bool checkThreshold(vector<int>&nums,int val,int threshold)
    {
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            int x=(nums[i]+val-1)/val;//for calculating ceil the formula is this
            ans+=x;      
        }
        return ans<=threshold;

    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        //using binary search
        //discover the range
        int n=nums.size();
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;

        while(l<=h)
        {
            int mid=(l+h)/2;
            if(checkThreshold(nums,mid,threshold))
            {
                ans=mid;
                h=mid-1;
                
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
        
    }
};
//
int main()
{
    vector<int>arr={44,22,33,11,1};
    int threshold=5;
    Solution s1;
    cout<<s1.smallestDivisor(arr,threshold);

}