//Given a string s. In one step you can insert any character at any index of the string.
//Return the minimum number of steps to make s palindrome.
//A Palindrome String is one that reads the same backward as well as forward.

// find shortest common supersequence of given string and reverse of the string,
// then subtract length of given string 
// find scs of string and reverse of string
// scs= sizeof(x)+sizeof(y)- length(lcs)
//length(scs)-length(string)

class Solution {
public:
    // find scs of string and reverse of string
    //length(scs)-length(string)
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
    int minInsertions(string s){
        int n=s.size();
        int m=n;
        string s2=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        int l=rec(s2,s,n,m,t);
        int scs=n+m-l;
        return scs-n;
    }
};