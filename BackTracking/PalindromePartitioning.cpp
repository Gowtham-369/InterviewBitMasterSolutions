bool isPalindrome(string s)
{
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}
bool IsPalindrome(string s, int l, int r)
{
    for (int i = l, j = r; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

vector<vector<string>> solve(int ind, int n, string s)
{
    vector<vector<string>> res;
    if (ind == n)
    {
        return res;
    }
    string start = "";
    for (int i = ind; i < n; i++)
    {
        start += s[i];

        if (!isPalindrome(start))
        {
            // cout<<"YES\n";
            continue;
        }
        vector<vector<string>> ans;

        ans = solve(i + 1, n, s);
        for (auto &vec : ans)
        {
            // cout<<"debug at "<<" ind "<<ind<<"\n";
            for (auto x : vec)
            {
                cout << x << " ";
            }
            cout << "\n";
            vec.insert(vec.begin(), start);
        }

        for (auto vec : ans)
        {
            res.push_back(vec);
        }
    }
    return res;
}
void solve2(int i, int n, string s, vector<string> temp, vector<vector<string>> &res)
{
    if (i >= n)
    {
        res.push_back(temp);
        return;
    }
    for (int j = i; j < n; j++)
    {
        if (IsPalindrome(s, i, j))
        {
            temp.push_back(s.substr(i, j - i + 1));
            solve2(j + 1, n, s, temp, res);
            temp.pop_back();
        }
    }
}
vector<vector<string>> Solution::partition(string A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    vector<vector<string>> res;
    // res = solve(0,n,A);
    vector<string> temp;
    solve2(0, n, A, temp, res);
    return res;
}
