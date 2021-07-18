bool cmp(const vector<int> &v1, const vector<int> &v2)
{
    return v1[2] < v2[2];
}
int find_set(int u, int parent[])
{
    if (u == parent[u])
    {
        return parent[u];
    }
    else
    {
        return parent[u] = find_set(parent[u], parent);
    }
}

void unionSet(int u, int v, int parent[], int rank[])
{
    int u_set = find_set(u, parent);
    int v_set = find_set(v, parent);

    if (rank[u_set] < rank[v_set])
    {
        parent[u_set] = v_set;
    }
    else if (rank[v_set] < rank[u_set])
    {
        parent[v_set] = u_set;
    }
    else
    {
        parent[u_set] = v_set;
    }
}

long long kruskalsAlgo(vector<vector<int>> B, int A, int n)
{
    // for disjoint union oprn
    int parent[A + 1], rank[A + 1];
    for (int i = 1; i <= A; ++i)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int minCost = 0;
    for (int i = 0; i < n; ++i)
    {
        /* Get each node src dest , weight */
        int u = B[i][0];
        int v = B[i][1];
        int cost = B[i][2];

        // check if it doesnt make cycle
        if (find_set(u, parent) != find_set(v, parent))
        {
            // add wt to min cost
            minCost = minCost + cost;
            // add parent of u to v
            unionSet(u, v, parent, rank);
        }
    }
    return minCost;
}

int Solution::solve(int A, vector<vector<int>> &B)
{
    int n = B.size();
    //sort on basis of 2nd col of B
    sort(B.begin(), B.end(), cmp);
    //call kruskals fn
    int minimumCost = kruskalsAlgo(B, A, n);
    return minimumCost;
}