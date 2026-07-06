class Solution {
public:
    void printPermute(vector<int>&ds,vector<vector<int>>&ans,vector<int>nums,vector<int> freq)
    {
        if(ds.size()==nums.size())//base case
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(freq[i]==0)//checks if the index is taken or not 
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                printPermute(ds,ans,nums,freq);//recursive call
                freq[i]=0;//once recursive call is completed elements are removed
                ds.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int> freq(n,0);
        printPermute(ds,ans,nums,freq);
        return ans;

        
    }
};