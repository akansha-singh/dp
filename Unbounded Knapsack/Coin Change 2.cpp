class Solution{
public:
    int rec(vector<vector<int>>&t,int W,vector<int>&S,int n){
        if (W == 0)
		    return 1;
	    if (n <= 0)
	  	    return 0;
	    if (t[n][W]!=-1)
		    return t[n][W];   
	    if (S[n-1]>W) 
		    return t[n][W] = rec(t,W,S,n-1);
	    else{		
		        return t[n][W] = rec(t,W,S,n-1)+rec(t,W-S[n-1],S,n);
	        } 
        }
    int change(int W,vector<int>&coins){
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return rec(dp,W,coins,n);
    }
};
