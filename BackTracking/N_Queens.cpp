bool issafe(int row, int col, int n, vector<vector<char>> temp)
{
    // cout<<"row "<<row<<":: col"<<col<<"\n";
    for (int j = 0; j < n; j++)
    {
        if (j != col && temp[row][j] == temp[row][col])
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != row && temp[i][col] == temp[row][col])
        {
            return false;
        }
    }
    //diagonally
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (temp[i][j] == 'Q')
        {
            return false;
        }
        i -= 1;
        j -= 1;
    }
    i = row + 1, j = col + 1;
    while (i < n && j < n)
    {
        if (temp[i][j] == 'Q')
        {
            return false;
        }
        i += 1;
        j += 1;
    }
    i = row - 1, j = col + 1;
    while (i >= 0 && j < n)
    {
        if (temp[i][j] == 'Q')
        {
            return false;
        }
        i -= 1;
        j += 1;
    }
    i = row + 1, j = col - 1;
    while (i < n && j >= 0)
    {
        if (temp[i][j] == 'Q')
        {
            return false;
        }
        i += 1;
        j -= 1;
    }
    return true;
}
void solve(int row, int n, vector<vector<char>> temp, vector<vector<string>> &res)
{

    if (row == n)
    {
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = 0; j < n; j++)
            {
                s += temp[i][j];
            }
            ans.push_back(s);
        }
        res.push_back(ans);
        return;
    }
    for (int j = 0; j < n && row < n; j++)
    {
        temp[row][j] = 'Q';
        if (issafe(row, j, n, temp))
        {
            // cout<<"YES\n";
            solve(row + 1, n, temp, res);
        }
        // cout<<"NO\n";
        temp[row][j] = '.';
    }
    return;
}
vector<vector<string>> Solution::solveNQueens(int n)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> res;
    vector<vector<char>> temp;
    // string row(n,'.');
    temp.resize(n, vector<char>(n, '.'));
    solve(0, n, temp, res);
    return res;
}
