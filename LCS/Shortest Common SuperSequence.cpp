// x=AGGTAB
// y=GXTXAYB
// shortest common supersequence is a shortest string which contains both strings
// so if we concatenate both given strings and remove one LCS the we obtain shortest common supersequence
// scs= sizeof(x)+sizeof(y)- length(lcs)
