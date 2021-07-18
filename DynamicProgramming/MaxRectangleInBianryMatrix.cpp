int Solution::maximalRectangle(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<pair<int, int>>> t(n, vector<pair<int, int>>(m, {0, 0}));
    //t[i][j] stores longest width and height ending at this element
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                //first row and first col
                if (i == 0 && j == 0)
                {
                    if (A[i][j] == 1)
                    {
                        t[i][j] = {1, 1};
                    }
                }
                else if (i == 0)
                {
                    if (A[i][j] == 1)
                    {
                        t[i][j] = {1 + t[i][j - 1].first, 1};
                    }
                }
                else if (j == 0)
                {
                    if (A[i][j] == 1)
                    {
                        t[i][j] = {1, 1 + t[i - 1][j].second};
                    }
                }
            }
            else
            {
                if (A[i][j] == 1)
                {
                    //x cordinate or width
                    t[i][j].first = 1 + t[i][j - 1].first;
                    //y cordinate or height
                    t[i][j].second = 1 + t[i - 1][j].second;
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<"(" << t[i][j].first<<","<<t[i][j].second<<") ";
    //     }
    //     cout<<"\n";
    // }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                //first row and first col
                ans = max(ans, t[i][j].first * t[i][j].second);
            }
            else
            {
                //max rectangle area ending at that [i][j]
                if (A[i][j] == 1)
                {
                    int n_ones = t[i][j].first;
                    int k = j;
                    int max_width = 1;
                    int max_height = t[i][j].second;
                    while (n_ones > 0 and t[i][k].second > 0)
                    {
                        max_height = min(max_height, t[i][k].second);
                        ans = max(ans, max_height * max_width);
                        k -= 1;
                        max_width += 1;
                        n_ones -= 1;
                    }
                    //trivial cases
                    //single row and single col cases
                    // ans = max(ans,t[i][j].first);
                    // ans = max(ans,t[i][j].second);
                }
            }
        }
    }
    return ans;
}
