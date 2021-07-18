int Solution::solve(const vector<int> &A) {
    int sum = 0,n=A.size();
    for(int i=0; i<n; i++){
        sum += A[i];
    }
    
    sum /= 2;
 
    long long int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
 
    for(int i=1;i<=sum;i++)
        dp[0][i] = INT_MAX;
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=A[i-1])
                dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-A[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
 
    return dp[n][sum];
    
    //subset sum
    /*
    for(int i=0; i<n; i++){
        sum += A[i];
    }
    
    int m = sum;
    // cout<<"sum "<<sum<<"\n";
    vector<vector<bool>> t(n+1,vector<bool>(m+1,false));
    for(int j=0; j<m+1; j++){
        t[0][j] = false;
    }
    for(int i=0; i<n+1; i++){
        t[i][0] = true;
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(A[i-1]<=j){
                t[i][j] = (t[i-1][j]||t[i-1][j-A[i-1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    int ans = n;
    int summ = 0;
    for(int i=sum/2; i>=0; i--){
        if(t[n][i] == true){
            summ = i;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if(t[i][summ] == true){
            ans = min(ans,i);
            break;
        }
    }
    return ans;
    */
    
    /*
    vector<int> v;
    v.assign(A.begin(),A.end());
    sort(v.begin(),v.end());
    int sum = 0;
    for(auto x:v){
        sum += x;
    }
    int n = v.size();
    int i;
    int sum2 = 0;
    for(i=n-1; i>=0; i--){
        sum2 += v[i];
        sum -= v[i];
        if(sum-sum2<0){
            break;
        }
    }
    // [i+1,n-1]
    return n-i-1;
    */
    
}
