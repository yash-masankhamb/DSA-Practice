class Solution {
public:
    void printf(int ind,vector<int>arr,vector<int>&ds,int target,vector<vector<int>>&ans)
    {
        // if(ind==arr.size())
        // {
        //     if(target==0)
        //    {
        //      ans.push_back(ds);
        //    }
        //     return;

        // }
        // if(arr[ind]<=target)
        // {
        //     ds.push_back(arr[ind]);
        //     printf(ind+1,arr,ds,target-arr[ind],ans);
        //     ds.pop_back();
        // }
       
        // printf(ind+1,arr,ds,target,ans);
        //the above code was for the brute force but the problem with this is that
        //for array [1,2,7,6,1,5] target=8 it gives (1,2,5) ansd also (2,1,5) which is repititive and we dont want this
        //so we use another recursive method which is optimized by sorting the array


        //also we have an alternate way that is the brute force and use set data structure to store the unique combination
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1])
            {
                continue;//tolerate the repititve elements
            }
            if(arr[i]>target)
            {
                break;
            }
            ds.push_back(arr[i]);
            printf(i+1,arr,ds,target-arr[i],ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        printf(0,candidates,ds,target,ans);
        return ans;
        
    }

   
};