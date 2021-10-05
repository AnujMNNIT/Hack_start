int trap(vector<int>& A) {
        int water=0,n=A.size();
        if(n==0)
            return 0;
        int l[n],r[n];
        l[0] = A[0];
        for(int i=1;i<n;i++)
            l[i]=max(l[i-1],A[i]);
        r[n-1]=A[n-1];
        for(int i=n-2;i>=0;i--)
            r[i] = max(r[i+1],A[i]);
        for(int i=1;i<n-1;i++)
            water += min(l[i],r[i])-A[i];
        
        return water;
    }
