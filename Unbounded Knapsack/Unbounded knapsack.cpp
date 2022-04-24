//fractional knapsack id not dp, is greedy
//Memoization Technique
// in unbounded multiple occurence of same item is allowed
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int rec(vector<vector<int>>&dp, int W, int wt[], int val[], int n){
        if(n==0||W==0)return 0;
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        if(wt[n-1]<=W){
            return dp[n][W]=max((val[n-1]+rec(dp,W-wt[n-1],wt,val,n)),rec(dp,W,wt,val,n-1));
        }else{
            return dp[n][W]=rec(dp,W,wt,val,n-1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return rec(dp,W,wt,val,n);
    }
};

 
