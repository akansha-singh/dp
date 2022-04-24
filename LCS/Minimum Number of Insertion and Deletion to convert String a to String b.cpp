// First find the lcs length
// No. of deletions= sizeof(x)-length of lcs
// No. of insertions= sizeof(y)-length of lcs
// OR
// if the question is 
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.
// The Code will be same
// First find the lcs length
// No. of deletions from left string= sizeof(x)-length of lcs
// No. of deletions from left string= sizeof(y)-length of lcs
class Solution{
	public:
	int lcs(string x, string y,int n,int m,vector<vector<int>>&t){
	    if(n==0||m==0)return 0;
        if(t[n][m]!=-1)return t[n][m];
        if(x[n-1]==y[m-1]){
            return t[n][m]= 1+lcs(x,y,n-1,m-1,t);
        }
        else{
            return t[n][m]= max(lcs(x,y,n-1,m,t),lcs(x,y,n,m-1,t));
        }
	}
	int minOperations(string text1, string text2) 
	{ 
	    int n=text1.size();
        int m=text2.size();
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        int l=lcs(text1,text2,n,m,t);  
        int ans=(n-l)+(m-l); 
        return ans;
	} 
};


