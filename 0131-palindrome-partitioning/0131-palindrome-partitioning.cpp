class Solution {
public:
    //so we need a function to check whether plindrome or not 
    bool ispalindrome(string s,int i,int j)
    {
        // string t="";
        // for(int i=s.size()-1;i>=0;i--)
        // {
        //     t+=s[i];
        // }
        // if(t==s)
        // {
        //     return true;
        // }
        // return false;
        //for more efficient approach
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void recur(int ind,string s,vector<string>&path,vector<vector<string>>&res)
    {
        if(ind==s.size())//base case
        {
            res.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(ispalindrome(s,ind,i))
            {
                path.push_back(s.substr(ind,i-ind+1));
                recur(i+1,s,path,res);
                path.pop_back();//backtracking method or removing from the data structure
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>res;

        recur(0,s,path,res);
        return res;

        
    }
};