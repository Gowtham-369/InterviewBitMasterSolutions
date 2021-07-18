void solve(int open, int closed, int n, string temp, vector<string> &ans)
{
    if (open == n && closed == n)
    {
        ans.push_back(temp);
        return;
    }
    if (open < n)
    {
        temp.push_back('(');
        solve(open + 1, closed, n, temp, ans);
        temp.pop_back();
        if (closed < open)
        {
            temp.push_back(')');
            solve(open, closed + 1, n, temp, ans);
        }
    }
    else if (closed < n)
    {
        temp.push_back(')');
        solve(open, closed + 1, n, temp, ans);
    }
    return;
}
vector<string> Solution::generateParenthesis(int n)
{
    int open = 0, closed = 0;
    vector<string> ans;
    string temp = "";
    solve(open, closed, n, temp, ans);
    return ans;
}
