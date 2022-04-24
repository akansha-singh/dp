/* A Naive recursive implementation of
0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){return (a > b) ? a : b; } // A utility function that returns maximum of two integers

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	// Base Case
	if (n == 0 || W == 0)
		return 0;
	// If weight of the nth item is more than Knapsack capacity W, then this item cannot be included in the optimal solution
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	// Return the maximum of two cases:// (1) nth item included // (2) not included
	else
		return max(val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n - 1),knapSack(W, wt, val, n - 1));}

// Driver code
int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}




//Memoization Technique

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
            return dp[n][W]=max((val[n-1]+rec(dp,W-wt[n-1],wt,val,n-1)),rec(dp,W,wt,val,n-1));
        }else{
            return dp[n][W]=rec(dp,W,wt,val,n-1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return rec(dp,W,wt,val,n);
    }
};
