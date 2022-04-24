//count the number of subsets such that. if we divide the array into 2 subsets then difference of all sum of all elements of these subsets should be x
//sum(s1)-sum(s2)=diff
//sum(s1)+sum(s2)=sum(arr)
//sum(s1)=(diff+sum(arr))/2
//given: diff=1, sum=7
//sum(s1)=4 => so return the count of subset whose sum is equl to 4


class Solution{
public:
    int rec(vector<int>&a,int n,int sum,vector<vector<int>>&t){
        if (sum == 0)
		    return 1;
	    if (n <= 0)      
		    return 0;
	    // If the value is not -1 it means it already call the function with the same value. it will save our                   from the repetition.
	    if (t[n - 1][sum] != -1)
		    return t[n - 1][sum];
	    // if the value of a[n-1] is greater than the sum. we call for the next value
	    if (a[n - 1] > sum)
		    return t[n - 1][sum] = rec(a, n - 1, sum,t);
	    else
	        {		
		        // Here we do two calls because we don't know which value is full-fill our criteria that's                      why we doing two calls
		        return t[n - 1][sum] = rec(a, n - 1, sum,t) +rec(a, n - 1, sum - a[n - 1],t);
	        }
        }
    int findTargetSumWays(vector<int>& nums, int diff){
        int n=nums.size();
        int sm=0;
        for(auto it:nums){
            sm=sm+it;
        }
        sm=ceil((diff+sum)/2.00);
        vector<vector<int>>t(n+1,vector<int>(sm+1,-1));
        return rec(nums,n,sm,t);
    }
};


