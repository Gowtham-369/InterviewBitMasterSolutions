// typedef long long ll;
using ll = long long;
long long min_cost(int idx, int n, int k, vector<pair<int, int>> &prsm, vector<vector<ll>> &t)
{

    if (idx >= n || (n - idx < k))
    {
        return INT_MAX; //not possible in K segments
    }
    if (k == 1)
    {
        int n_w = (prsm[n].first - prsm[idx].first);
        int n_b = (prsm[n].second - prsm[idx].second);
        return n_w * n_b;
    }
    if (t[idx][k] < INT_MAX)
    {
        return t[idx][k];
    }
    long long ans = INT_MAX;
    for (int i = idx; i < n; i++)
    {
        int n_w = (prsm[i + 1].first - prsm[idx].first);
        int n_b = (prsm[i + 1].second - prsm[idx].second);
        // long long res = (n_w*n_b)+min_cost(i+1,n,k-1,prsm,t);
        if (t[i + 1][k - 1] == INT_MAX)
        {
            t[i + 1][k - 1] = min_cost(i + 1, n, k - 1, prsm, t);
        }
        ll res = (n_w * n_b) + t[i + 1][k - 1];
        ans = min(ans, res);
    }
    return t[idx][k] = ans;
}
int Solution::arrange(string A, int B)
{
    if (B == 0)
    {
        return -1;
    }
    int n = A.size();
    vector<pair<int, int>> prsm(n + 1);
    int n_w = 0, n_b = 0;
    prsm[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        if (A[i - 1] == 'W')
        {
            n_w += 1;
        }
        else
        {
            n_b += 1;
        }
        prsm[i] = {n_w, n_b};
    }
    vector<vector<ll>> t(n + 1, vector<ll>(B + 1, INT_MAX));
    long long ans = min_cost(0, n, B, prsm, t);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}
