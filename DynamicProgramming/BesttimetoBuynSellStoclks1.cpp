int Solution::maxProfit(const vector<int> &A)
{
    int n = A.size();
    int minn = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            ans = max(ans, A[i] - minn);
        }
        minn = min(minn, A[i]);
    }
    return ans;
}
