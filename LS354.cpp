class Solution {
    
    int ceil(vector<pair<int,int>> &vect,pair<int,int> val)
    {
        //Jab dono chhota hoga tabhi search space ke left me jayenge
        
        int l=0,h=vect.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(vect[mid]==val)
                return mid;
            else if(vect[mid].first<val.first&&vect[mid].second<val.second)
            {
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return l;
    }
public:
    int maxEnvelopes(vector<vector<int>>& A)
    {
        sort(A.begin(),A.end(),cmp);
        int n=A.size(),i,j;
         if(n<=1)
            return n;
        vector<pair<int,int> > vect;
        vect.push_back(make_pair(A[0][0],A[0][1]));
        for(i=0;i<n;i++)
        {
           int index=ceil(vect,make_pair(A[i][0],A[i][1]));
           if(index==vect.size())
            vect.push_back(make_pair(A[i][0],A[i][1]));
           else
            vect[index]=make_pair(A[i][0],A[i][1]);
        }
        return vect.size();
    }
};
