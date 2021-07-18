vector<int> Solution::slidingMaximum(const vector<int> &A, int w)
{
    deque<int> dq;
    int n = A.size();
    vector<int> res;
    if (n < w)
        return res;
    res.resize(n - w + 1);
    for (int i = 0; i < w; i++)
    {
        while (!dq.empty() && A[i] >= A[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = w; i < n; i++)
    {
        res[i - w] = A[dq.front()]; //max element at front()
        while (!dq.empty() && A[i] >= A[dq.back()])
        {
            dq.pop_back();
        }
        while (!dq.empty() && dq.front() <= i - w)
        {
            dq.pop_front();
        }
        dq.push_back(i);
    }
    res[n - w] = A[dq.front()];
    return res;
}
