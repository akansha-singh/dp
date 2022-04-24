class Solution{
public:
    int rec(vector<int>a,int n,int sum,vector<vector<int>>&t){
        if (sum == 0)
		    return 1;
	    if (n <= 0)      
		    return 0;
	    // If the value is not -1 it means it already call the function with the same value. it will save our from the repetition. 
	    if (t[n - 1][sum] != -1)
		    return t[n - 1][sum];
	    // if the value of a[n-1] is greater than the sum. we call for the next value
	    if (a[n - 1] > sum)
		    return t[n - 1][sum] = rec(a, n - 1, sum,t);
	    else
	        {		
		        // Here we do two calls because we don't know which value is full-fill our criteria that's why we doing two calls
		        return t[n - 1][sum] = rec(a, n - 1, sum,t)||rec(a, n - 1, sum - a[n - 1],t);
	        }
        }
    bool canPartition(vector<int>& nums){
        int n=nums.size();
        int sm=0;
        for(auto it:nums){
            sm=sm+it;
        }
        if(sm%2!=0)return 0; //imp
        sm=(sm/2);
        cout<<sm<<" ";
        vector<vector<int>>t(n+1,vector<int>(sm+1,-1));
        return rec(nums,n,sm,t);
    }
};