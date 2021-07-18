class compare
{
public:
    inline bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
};
void dfs(int i, int j, set<int> &s1, set<int> &s2, vector<int> &vis, vector<int> &A, vector<int> &B, unordered_map<int, vector<int>> &mp1)
{
    vis[i] = 1;
    s1.insert(A[i]);
    s2.insert(B[j]);
    for (int idx : mp1[j])
    {
        if (!vis[idx])
        {
            dfs(idx, idx, s1, s2, vis, A, B, mp1);
        }
    }
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int>> &C)
{
    unordered_map<int, vector<int>> mp1;
    int n = C.size();
    for (auto vec : C)
    {
        mp1[vec[0] - 1].push_back(vec[1] - 1);
        mp1[vec[1] - 1].push_back(vec[0] - 1);
    }
    int m = A.size();
    vector<int> vis(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        set<int> s1, s2;
        if (vis[i] == 0)
        {
            dfs(i, i, s1, s2, vis, A, B, mp1);
            if (s1 != s2)
            {
                return 0;
            }
        }
    }
    return 1;
}
