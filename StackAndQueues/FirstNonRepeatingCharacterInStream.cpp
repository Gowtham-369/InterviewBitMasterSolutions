string Solution::solve(string A)
{
    deque<char> dq;
    map<char, int> mp;
    int n = A.size(), i = 0;
    string res = "";
    while (i < n)
    {
        char cur = A[i];

        dq.push_back(cur);
        mp[cur] += 1;
        while (!dq.empty() && mp[dq.front()] > 1)
        {
            dq.pop_front();
        }
        if (dq.empty())
        {
            res += '#';
        }
        else
        {
            res += dq.front();
        }

        i += 1;
    }
    return res;
}
