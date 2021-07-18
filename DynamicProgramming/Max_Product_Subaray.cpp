int Solution::maxProduct(const vector<int> &A)
{
    int n = A.size();
    // map<int,pair<int,int>> mp;
    vector<pair<int, int>> mp(n + 1);
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        if (j >= 0)
        {
            int minn = mp[j].first;
            int maxx = mp[j].second;
            if (A[i] >= 0)
            {
                int minn2 = minn * A[i];
                int maxx2 = maxx * A[i];
                mp[i].first = min(A[i], minn2);
                mp[i].second = max(A[i], maxx2);
            }
            else
            {
                int minn2 = maxx * A[i];
                int maxx2 = minn * A[i];
                mp[i].first = min(A[i], minn2);
                mp[i].second = max(A[i], maxx2);
            }
        }
        else
        {
            mp[i].first = A[i];
            mp[i].second = A[i];
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, mp[i].second);
    }
    return ans;
}
