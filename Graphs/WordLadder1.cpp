int Solution::solve(string A, string B, vector<string> &C)
{

    queue<string> q;
    q.push(A);

    unordered_map<string, bool> dict;
    for (int i = 0; i < C.size(); i++)
        dict[C[i]] = 0;

    int count = 1;

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            string curr = q.front();
            string temp = curr;
            q.pop();

            if (dict.find(B) != dict.end() && dict[B])
                return count;

            for (int i = 0; i < curr.size(); i++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    curr[i] = c;
                    if (dict.find(curr) != dict.end() && !dict[curr])
                    {
                        dict[curr] = 1;
                        q.push(curr);
                    }
                    curr[i] = temp[i];
                }
            }
        }
        count++;
    }
    return -1;
}