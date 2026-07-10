class Solution {
public:
    void printpermute(int index,vector<int>&nums,set<vector<int>>& s)
    {
        if(index==nums.size())//base case
        {
            s.insert(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            printpermute(index+1,nums,s);
            swap(nums[index],nums[i]);
                    
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // i am using an optimal approach to the permutations problem
        //that do not uses the map but ill be using a set to store only unique arrays
        set<vector<int>> s;//stores the ans
        printpermute(0,nums,s);
        //set to vector conversion
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;

        
    }
};
