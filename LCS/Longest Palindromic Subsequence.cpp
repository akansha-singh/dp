// apne aap mai ek pattern hai. has many sub problems
// but no.. it is child of LCS 
// length of longest palindromic subsequence = LCS(string,reverse of string)

class Solution {
public:
    int rec(string x,string y,int n,int m,vector<vector<int>>&t){
        if(n==0||m==0)return 0;
        if(t[n][m]!=-1)return t[n][m];
        if(x[n-1]==y[m-1]){
            return t[n][m]= 1+rec(x,y,n-1,m-1,t);
        }
        else{
            return t[n][m]= max(rec(x,y,n-1,m,t),rec(x,y,n,m-1,t));
        }
    }
    int longestPalindromeSubseq(string s){
        int n=s.size();
        int m=n;
        string s2=s;
        reverse(s.begin(),s.end());         
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        return rec(s2,s,n,m,t);
    }
};

