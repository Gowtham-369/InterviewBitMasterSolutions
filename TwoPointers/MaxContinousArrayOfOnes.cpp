vector<int> Solution::maxone(vector<int> &A, int B)
{
    int n = A.size();
    int i = 0, l = 0;
    int cnt = 0;
    int ans = INT_MIN;
    int start = 0;
    while (i < n)
    {
        if (A[i] == 0)
        {
            cnt += 1;
        }
        while (cnt > B)
        {
            if (A[l] == 0)
            {
                cnt -= 1;
            }
            l += 1;
        }
        int len = (i - l + 1);
        if (ans < len)
        {
            ans = len;
            start = l;
        }
        i += 1;
    }
    vector<int> res;
    for (int j = start; j < (start + ans); j++)
    {
        res.push_back(j);
    }
    return res;
}
