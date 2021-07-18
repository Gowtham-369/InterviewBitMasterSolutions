vector<int> adj[10005];
bool isvalid(string s, string p)
{
    int n = s.length();
    int m = p.length();
    int cnt = abs(n - m);
    int i = 0, j = 0;
    if (cnt > 1)
        return false;
    while (i < n && j < m)
    {
        if (s[i] != p[j])
            cnt++;
        if (cnt > 1)
            return false;
        i++;
        j++;
    }
    return (cnt == 1);
}
void dfs(int node, int fin, vector<string> &temp, set<vector<string>> &ret, int cost, int low, vector<string> &dict)
{
    if (cost == low)
    {
        if (node == fin)
            ret.insert(temp);
        return;
    }
    for (auto it : adj[node])
    {
        temp.push_back(dict[it - 1]);
        dfs(it, fin, temp, ret, cost + 1, low, dict);
        temp.pop_back();
    }
}
vector<vector<string>> Solution::findLadders(string start, string end, vector<string> &dict)
{
    vector<string> temp;
    temp.push_back(start);
    vector<vector<string>> ret;
    if (start == end)
    {
        ret.push_back(temp);
        return ret;
    }
    for (int i = 0; i < 10005; i++)
        adj[i].clear();
    int n = dict.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (isvalid(dict[i], dict[j]))
                adj[i + 1].push_back(j + 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (isvalid(start, dict[i]))
            adj[0].push_back(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (isvalid(dict[i], end))
            adj[i + 1].push_back(n + 1);
    }
    if (isvalid(start, end))
        adj[0].push_back(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> cost(n + 2, INT_MAX);
    pq.push({0, 0});
    cost[0] = 0;
    while (!pq.empty())
    {
        int cst = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            if (cst + 1 < cost[it])
            {
                cost[it] = cst + 1;
                pq.push({cost[it], it});
            }
        }
    }
    int low = cost[n + 1];
    if (low == INT_MAX)
        return ret;
    dict.push_back(end);
    set<vector<string>> st;
    dfs(0, n + 1, temp, st, 0, low, dict);
    for (auto it : st)
        ret.push_back(it);
    return ret;
}