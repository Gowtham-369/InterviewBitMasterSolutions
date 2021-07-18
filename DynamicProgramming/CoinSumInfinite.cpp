const int mod = 1000007;
int n_ways(vector<int> &A, int target, int n)
{
    if (target == 0)
    {
        return 1;
    }
    if (n <= 0)
    {
        return 0;
    }
    if (target >= A[n - 1])
    {
        return n_ways(A, target - A[n - 1], n) + n_ways(A, target, n - 1);
    }
    else
    {
        return n_ways(A, target, n - 1);
    }
}
int Solution::coinchange2(vector<int> &A, int B)
{
    int n = A.size();
    // int ans = n_ways(A,B,n);
    /*
    vector<vector<int>> t(n+1,vector<int>(B+1,0));
    for(int i=0; i<=n; i++){
        t[i][0] = 1;
    }
    for(int j=1; j<=B; j++){
        t[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=B; j++){
            if(j>=A[i-1]){
                t[i][j] = (t[i][j-A[i-1]]%mod+t[i-1][j]%mod)%mod;
            }
            else{
                t[i][j] = t[i-1][j]%mod; 
            }
        }
    }
    return t[n][B];
    // return ans;
    */
    int t[B + 1];
    memset(t, 0, sizeof(t));
    t[0] = 1;
    for (auto x : A)
    {
        for (int i = 1; i <= B; i++)
        {
            if (i - x >= 0)
            {
                t[i] = (t[i] + t[i - x]) % mod;
            }
        }
    }
    return t[B];
}
