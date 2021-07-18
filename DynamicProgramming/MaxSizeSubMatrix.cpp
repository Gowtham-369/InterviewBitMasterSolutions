int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < A[i].size(); j++)
        {
            if (A[i][j] == 1)
            {
                int x = min(A[i - 1][j - 1], min(A[i - 1][j], A[i][j - 1]));
                A[i][j] = x + 1;
            }
        }
    }
    int side = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            // cout<<A[i][j]<<" ";
            side = max(side, A[i][j]);
        }
        // cout<<"\n";
    }
    return side * side;
}
