int max_sum(int i, int j, vector<vector<int>> &A)
{
    if (i == 1 or j == 1)
    {
        return A[0][0];
    }
    int n = A.size();
    int n_zeros = n - (i + 1);
    int j_limit = n - n_zeros;
    if (j >= j_limit)
    {
        return 0;
    }
    return max(A[i - 1][j] + max_sum(i - 1, j, A), A[i - 1][j - 1] + max_sum(i - 1, j - 1, A));
}
int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    // return max(A[n-2][n-1]+max_sum(n-2,n-1,A),A[n-2][n-2]+max_sum(n-2,n-2,A));

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                A[i][j] += A[i - 1][j];
            }
            else
                A[i][j] += max(A[i - 1][j], A[i - 1][j - 1]);
        }
    }
    int ans = INT_MIN;
    for (int j = 0; j < n; j++)
    {
        ans = max(ans, A[n - 1][j]);
    }
    return ans;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // return A[n-1][n-1];
}
