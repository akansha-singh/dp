// Recursive 
class Solution{
    public:
    int rec(string x,string y,int n,int m,int maxm){
        if(n==0||m==0)return maxm;
        if(x[n-1]==y[m-1]){         //explain choice diagram
            maxm= rec(x,y,n-1,m-1,maxm+1);
        }
        maxm = max(maxm,max(rec(x,y,n,m-1,0),rec(x,y,n-1,m,0)));
        return maxm;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        return rec(S1,S2,n,m,0);
    }
};


// Memoization
class Solution{
    public:
    int maxm=INT_MIN;
    int rec(string x,string y,int n,int m,vector<vector<int>>&t){
        if(n==0||m==0)return 0;     //base case
        if(t[n][m]!=-1)return t[n][m];
        if(x[n-1]==y[m-1]){         //explain choice diagram
            t[n][m]= 1+rec(x,y,n-1,m-1,t);
        }
        else{
            t[n][m]=0;              //imp
        }
        rec(x,y,n,m-1,t);
        rec(x,y,n-1,m,t);
        maxm = max(maxm,t[n][m]);
        return t[n][m];
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        rec(S1,S2,n,m,t);
        return maxm;
    }
};






