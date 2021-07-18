vector<string> solve(string A, map<string, int> &mp)
{
    vector<string> res;
    if ((int)A.size() == 0)
    {
        res.push_back(" ");
        return res;
    }
    for (int i = 1; i <= (int)A.size(); i++)
    {
        string s = A.substr(0, i);
        if (mp.find(s) != mp.end())
        {
            vector<string> v = solve(A.substr(i), mp);
            if (v.size() > 0)
            {
                for (auto x : v)
                {
                    string ans = s + " " + x;
                    res.push_back(ans);
                }
            }
        }
    }
    return res;
}
vector<string> Solution::wordBreak(string A, vector<string> &B)
{
    map<string, int> mp;
    for (auto s : B)
    {
        mp[s] += 1;
    }
    vector<string> ans = solve(A, mp);
    for (auto &s : ans)
    {
        //two empty spaces at the end of every final
        //one space for successfull completion of given string
        //one space for work break
        //so two spaces for last word in the broken string
        s.pop_back();
        s.pop_back();
    }
    return ans;
}
