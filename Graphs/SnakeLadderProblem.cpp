int Solution::snakeLadder(vector<vector<int>> &ladder, vector<vector<int>> &snake)
{
    map<int, int> msnakes, mladders;
    int n = ladder.size(), m = snake.size();
    vector<int> dp(101, 100000);
    for (int i = 0; i < n; i++)
    {
        mladders[ladder[i][0]] = ladder[i][1];
    }
    for (int i = 0; i < m; i++)
    {
        msnakes[snake[i][0]] = snake[i][1];
    }
    dp[1] = 0;
    for (int k = 1; k <= 100; k++)
        for (int i = 1; i <= 100; i++)
        {
            if (mladders[i]) //ladder exist
            {
                dp[mladders[i]] = min(dp[mladders[i]], dp[i]);
            }
            else if (msnakes[i] == 0) //no snakes and ladder
            {
                for (int j = 1; j <= 6; j++)
                {
                    if (i + j <= 100 || msnakes[i + j] == 0)
                    {
                        dp[i + j] = min(dp[i + j], 1 + dp[i]);
                    }
                }
            }
            else //snake exist
            {
                dp[msnakes[i]] = min(dp[msnakes[i]], dp[i]);
            }
        }

    if (dp[100] == 100000)
        return -1;
    return dp[100];
}