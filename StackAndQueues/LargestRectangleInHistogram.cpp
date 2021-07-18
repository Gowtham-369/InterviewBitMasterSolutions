int Solution::largestRectangleArea(vector<int> &A)
{
    int ans = INT_MIN;
    int n = A.size(), i = 0;
    vector<int> right(n), left(n);
    stack<int> st;
    // 2, 1, 5, 6, 2, 3
    //right : 1 6 4 4 5 6
    while (i < n)
    {
        while (!st.empty() && A[i] < A[st.top()])
        {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
        i += 1;
    }
    //i==n
    while (!st.empty())
    {
        right[st.top()] = i;
        st.pop();
    }

    i = n - 1;
    while (i >= 0)
    {
        while (!st.empty() && A[i] < A[st.top()])
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
        ans = max(ans, (right[i] - left[i] - 1) * A[i]);
    }
    return ans;
}
