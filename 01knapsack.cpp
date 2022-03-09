/* A Naive recursive implementation of
0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
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

















//Method 3: This method uses Memoization Technique

#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
// Returns the value of maximum profit
int knapSackRec(int W, int wt[],int val[], int i,int** dp)
{
	// base condition
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W) {
		// Store the value of function call stack in table before return
		dp[i][W] = knapSackRec(W, wt,val, i - 1,dp);
		return dp[i][W];
	}
	else {
		// Store value in a table before return
		dp[i][W] = max(val[i]+ knapSackRec(W - wt[i],wt, val,i - 1, dp),knapSackRec(W, wt, val,i - 1, dp));

		// Return value of table after storing
		return dp[i][W];
	}
}

// Driver Code
int main()
{
    memset(dp, -1, sizeof(dp));
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSackRec(W, wt, val, n,dp);
	return 0;
}


