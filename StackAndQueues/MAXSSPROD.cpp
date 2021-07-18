const int mod = 1e9 + 7;
int Solution::maxSpecialProduct(vector<int> &A)
{
    int n = A.size(), i = 0;
    stack<int> st;
    vector<long long> right(n), left(n);
    long long int ans = 0;
    while (i < n)
    {
        while (!st.empty() && A[i] > A[st.top()])
        {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
        i += 1;
    }
    while (!st.empty())
    {
        right[st.top()] = i;
        st.pop();
    }
    i = n - 1;
    while (i >= 0)
    {
        while (!st.empty() && A[i] > A[st.top()])
        {
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
        i -= 1;
    }
    //i == -1
    while (!st.empty())
    {
        left[st.top()] = i;
        st.pop();
    }
    for (i = 0; i < n; i++)
    {
        if (left[i] != -1 && right[i] != n)
        {
            ans = max(ans, left[i] * right[i]);
        }
    }
    if (ans < 0)
    {
        ans = (ans + mod) % mod;
    }
    return (int)(ans % mod);
}
