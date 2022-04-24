// length of longest palindromic substring = Longest Common Substring(string,reverse of string)
class Solution{   
public:
    int maxm=INT_MIN;
    int rec(string x,string y,int n,int m,vector<vector<int>>&t){
        if(n==0||m==0)return 0;     //base case
        if(t[n][m]!=-1)return t[n][m];
        if(x[n-1]==y[m-1]){         //explain choice diagram
            t[n][m]= 1+rec(x,y,n-1,m-1,t);
        }
        else{
            t[n][m]=0;              //imp
        }
        rec(x,y,n,m-1,t);
        rec(x,y,n-1,m,t);
        maxm = max(maxm,t[n][m]);
        return t[n][m];
    }
    string longestPalindrome(string s){
        // code here   
        int n=s.size();
        int m=n;
        string s2=s;
        reverse(s.begin(),s.end());         
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        rec(s2,s,n,m,t);
        return maxm;
    }
};