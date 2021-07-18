int solveLCS(string A, string B)
{
    int n = A.size(), m = B.size();
    vector<vector<int>> t(n + 1, vector<int>(m + 1));
    // fill(t.begin(),t.end(),vector<int>(m+1,0));

    for (int j = 0; j < m + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1; //"abc" and "",there is one way
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + t[i - 1][j]; //even after match
                //rabbitt
                //rabbit
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][m]; //no of ways
}
int Solution::numDistinct(string A, string B)
{
    return solveLCS(A, B);
}