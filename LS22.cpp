class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s="";
        helper(0,0,n,res,s);
        return res;
        
    }
    void helper(int close,int open,int n,vector<string>& res,string s)
    {
        if(s.length()==2*n)
        {
            res.push_back(s);
            return ;
        }
        if(open<n)
            helper(close,open+1,n,res,s+'(');
        if(close<open)
            helper(close+1,open,n,res,s+')');
    }
};
