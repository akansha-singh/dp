//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
// A Dynamic Programming solution
// for subset sum problem
// A recursive solution for subset sum problem


// subset sum and subset sum count are similar bass OR ka + kar diya tha.


#include <iostream>
using namespace std;

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{

	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0)
		return false;

	// If last element is greater than sum,
	// then ignore it
	if (set[n - 1] > sum)					// if else
		return isSubsetSum(set, n - 1, sum);

	/* else, check if sum can be obtained by any
of the following:
	(a) including the last element
	(b) excluding the last element */
	return isSubsetSum(set, n - 1, sum)
		|| isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Driver code
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		cout <<"Found a subset with given sum";
	else
		cout <<"No subset with given sum";
	return 0;
}




// Memoization
class Solution{   
public:
    int rec(vector<int>a,int n,int sum,vector<vector<int>>&t){
        if (sum == 0)
		    return 1;
	    if (n <= 0)      
		    return 0;
	    // If the value is not -1 it means it already call the function with the same value. it will save our from the repetition.
	    if (t[n][sum] != -1)
		    return t[n][sum];
	    // if the value of a[n-1] is greater than the sum. we call for the next value
	    if (a[n-1] > sum)
		    return t[n][sum] = rec(a, n-1, sum,t);
	    else
	        {		
		        // Here we do two calls because we don't know which value is full-fill our criteria that's why we doing two calls
		        return t[n][sum] = rec(a, n - 1, sum,t)||rec(a, n - 1, sum - a[n - 1],t);
	        }
        }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>t(n+1,vector<int>(sum+1,-1));
        if(rec(arr,n,sum,t)){
            return true;
        }else{
            return false;
        }
    }
};

