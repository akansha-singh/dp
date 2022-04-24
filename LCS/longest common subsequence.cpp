// x= a b c d g h
// y= a b f d g h r
// longest common subsequence-> a b d g h  , have to return length
// longest common substring-> a b 


// Recursive
class Solution{
public:
    int rec(string x, string y,int n1,int n2){
        if(n1==0||n2==0)return 0;   // base case
        if(x[n1-1]==y[n2-1]){   //choice diagram
            return 1+rec(x,y,n1-1,n2-1);
        }
        else{
            return max(rec(x,y,n1-1,n2),rec(x,y,n1,n2-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2){
        int n1=text1.size();
        int n2=text2.size();
        return rec(text1,text2,n1,n2);
    }
};

// Memoization
class Solution{
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
    int longestCommonSubsequence(string text1, string text2){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        return rec(text1,text2,n,m,t);
    }
};