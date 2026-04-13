#include<iostream>
using namespace std;
class Solution {
public:
   
    int getMinDistance(vector<int>& nums, int target, int start) {
      //simple O(n)approch is enough to solve this problem
        int n=nums.size();
        int index=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(target==nums[i])
            {
                index=i;
                ans=min(ans,abs(i-start));
            }
        }
 
        return ans;


        
    }
};
int main()
{
    vector<int>arr={1,1,1,1,1,1,1,1,1,1};
    int target=1;
    int start=0;
    Solution s1;
    cout<<s1.getMinDistance(arr,target,start);

}
//Sample test case
// nums =[1,2,3,4,5]
// target =5
// start =3
// Expected  1