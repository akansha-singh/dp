// Minimum number of deletion in a string to make it a palindrome=Length of string - Length of longest palindromic subsequence
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
int minDeletions(string s, int n){ 
    //complete the function here 
    int m=n;
    string s2=s;
    reverse(s.begin(),s.end());
    vector<vector<int>>t(n+1,vector<int>(m+1,-1));
    int l=rec(s2,s,n,m,t);
    return n-l;
} 