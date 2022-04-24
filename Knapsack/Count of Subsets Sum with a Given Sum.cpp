// subset sum and subset sum count are similar bass OR ka + kar diya tha.
class Solution{
	public:
    int rec(int a[],int n,int sum,vector<vector<int>>&t){
        if (sum == 0)
		    return 1;
	    if (n <= 0)
	  	    return 0;
	    // If the value is not -1 it means it already call the function with the same value. it will save our from the repetition.
	    if (t[n][sum] != -1)
		    return t[n][sum];
	    // if the value of a[n-1] is greater than the sum. we call for the next value
	    if (a[n-1] > sum)
		    return t[n][sum] = rec(a, n - 1, sum,t);
	    else
	        {		
		        // Here we do two calls because we don't know which value is full-fill our criteria that's why we doing two calls
		        return t[n][sum] = rec(a,n-1,sum,t)+rec(a,n-1,sum-a[n-1],t);
	        }
        }
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>t(n+1,vector<int>(sum+1,-1));
        return rec(arr,n,sum,t);
	}
};