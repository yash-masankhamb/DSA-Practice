class Solution {
public:
    void printf(int ind,vector<int>arr,vector<int>&ds,vector<vector<int>>&ans)
    {
         ans.push_back(ds);//every recursion call represents a valid subset 
        if(ind==arr.size())//base case 
        {

            return;
        }
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1])//for not duplicate subsets
            {
                continue;
            }
            ds.push_back(arr[i]);
            printf(i+1,arr,ds,ans);
            ds.pop_back();
        }
    

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());//sorting is a prerequisite for finding unique subsets
        printf(0,nums,ds,ans);
        return ans;
        
    }
};