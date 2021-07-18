int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    vector<int> t(n + 1, 1); //single pair alone contributes 1
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j][1] < A[i][0])
            {
                t[i] = max(t[i], 1 + t[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, t[i]);
    }
    return ans;
}
