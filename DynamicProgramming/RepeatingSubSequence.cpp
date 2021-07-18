bool Isthere(string to_find,string s,int n,int m){
    int i=0;
    
    for(int j=0; j<n && i<m; j++){
        if(s[j] == to_find[i]){
            i += 1;
        }
    }
    if(i==m){
        return true;
    }
    else{
        return false;
    }
}
int Solution::anytwo(string A) {
    int n = A.size();
    /*
    for(char ch1 = 'a';ch1<='z'; ch1++){
        string s = "";
        s += ch1;
        s += ch1;
        s += ch1;
        if(Isthere(s,A,n,3)){
            return 1;
        }
        for(char ch2='a'; ch2<='z';ch2++){
            s = "";
            s += ch1;s += ch2;
            s = s + s;
            if(Isthere(s,A,n,4)){
                return 1;
            }
            s = "";
            s += ch1;s += ch1;
            s += ch2;s += ch2;
            if(Isthere(s,A,n,4)){
                return 1;
            }
        }
    }
    return 0;
    */
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(A[i-1]==A[j-1]&&i!=j)
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    if(dp[n][n]>=2)
    return 1;
    else
    return 0;
        
}